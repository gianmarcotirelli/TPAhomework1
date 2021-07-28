#ifndef GTPRESSA
#define GTPRESSA

#include <iostream>
#include <cmath>
#include <string.h>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <iomanip>

using namespace std;

struct GTdevicePressa {
    double l1;
    double l2;
    double l3;
    double distance;
    double angle;
    double height;
    double width;
};

/**
 * Inizializza una struttura di tipo GTdevicePressa e controlla che i parametri siano compatibili attraverso il metodo GT
 * l1 = lunghezza dell'asta che collega A con la coppia centrale
 * l2 = lunghezza dell'asta che collega T con la coppia centrale
 * l3 = lunghezza dell'asta che collega B con la coppia centrale
 * distance = distanza tra il telaio T e il cilindro A
 * angle = angolo tra l'asta l2 e la verticale. Ne determina la configurazione iniziale. 
 *          Non sono accettabili solo angoli che risultano in una configurazione singolare del meccanismo, ma per essere funzionale il range consigliato va da 0 rad a 0.8 rad.
 * height = altezza dei cilindri
 * width = larghezza dei cilindri 
 */ 

GTdevicePressa* GTinitPressa (double l1, double l2, double l3, double distance, double angle, double height, double width);

/**
 *Controlla che i parametri permettano al meccanismo di assemblarsi correttamente.
 *Se uno dei parametri è <= 0 ritorna il codice 1
 *Se l'angolo di montaggio corrisponde ad una delle configurazioni singolari ritorna il codice 2
 *Se la lunghezza distance è maggiore di l2 rtirona il codice 3
 *Se l1 + l2 < distanza il meccanismo non si assembla e ritorna 4
 *Viene anche controllato che height e width siano proporzionati alle aste (codice 6,7,8)
 *Se tutti i parametri sono compatibili ritorna 0 e il device viene inizializzato
 */
int GTCheckParam(GTdevicePressa* pressa);

/**
 *Metodi per settare un signolo parametro.
 *Ritornano 1 se il meccanismo non si dovesse assemblare
 */

int GTSetL1(GTdevicePressa* pressa, double l1);
int GTSetL2(GTdevicePressa* pressa, double l2);
int GTSetL3(GTdevicePressa* pressa, double l3);
int GTSetDistance(GTdevicePressa* pressa, double distance);
int GTSetAngle(GTdevicePressa* pressa, double angle);
int GTSetHeight(GTdevicePressa* pressa, double height);
int GTSetWidth(GTdevicePressa* pressa, double width);

/**
 *Restituisce una string di codice SVG per disegnare il meccanismo. Se measures = 1 restituisce il disegno con le misure 
 */
string GTtoStringSGV (GTdevicePressa* pressa, bool measures);

/**
 * Serie di metodi per calcolare posizioni e angoli degli elementi del device
 */
inline double GTgetxT(GTdevicePressa* pressa){ return pressa->l2 + pressa->l3;};
inline double GTgetyT(GTdevicePressa* pressa){ return pressa->l1;};
inline double GTgetRadius(GTdevicePressa* pressa) {return pressa->width/3;};
inline double GTgetq(GTdevicePressa* pressa) {return 4.71 - pressa->angle;};
inline double GTgetxC(GTdevicePressa* pressa) {return GTgetxT(pressa) - pressa->l2 * sin(pressa->angle);}
inline double GTgetyC(GTdevicePressa* pressa) {return GTgetyT(pressa) + pressa->l2 * cos(pressa->angle);}
inline double GTgetxB(GTdevicePressa* pressa) {return GTgetxT(pressa);}
inline double GTgetyB(GTdevicePressa* pressa) {
    double aC = acos(pressa->l2 * cos(GTgetq(pressa)) / pressa->l3);
    return GTgetyT(pressa) - (pressa->l2 * sin(GTgetq(pressa))) + (pressa->l3 * sin(aC));
}
inline double GTgetxA(GTdevicePressa* pressa){ return GTgetxT(pressa) - pressa->distance;}
inline double GTgetyA(GTdevicePressa* pressa) {
    double aA = acos((+(pressa->l2 * cos(GTgetq(pressa))) + pressa->distance) / pressa->l1); // angolo assoluto in A
    return GTgetyT(pressa) + (pressa->l2 * sin(GTgetq(pressa))) + (pressa->l1 * sin(aA));
}

/**
 * Tronca le stringe 
 */ 
string GTtrunc(string value, int precision);


/**
 * Riceve in input una stringa s dal metodo GTtoStringSGV e il nome del file in cui si vuole salvarla
 */ 
void GTSaveToFile(string s, string name);

/**
 * Riceve in input il nome del file e restituisce il codice svg del device
 */ 
string GTLoadFromFile (string name);

/**
 * Cancella il device
 */ 
void GTDeleteDevice(GTdevicePressa* pressa);



#endif 