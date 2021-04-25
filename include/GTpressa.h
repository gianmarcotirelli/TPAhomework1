#ifndef GTPRESSA_H
#define GTPRESSA_H

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

struct GTdevicePressa {
    double l1;
    double l2;
    double l3;
    double distance;
    double height;
    double width;
};

/**
 * Inizializza una struttura di tipo GTdevicePressa e controlla che i parametri siano compatibili attraverso il metodo CheckParam
 * l1 = lunghezza dell'asta che collega A con la coppia centrale
 * l2 = lunghezza dell'asta che collega T con la coppia centrale
 * l3 = lunghezza dell'asta che collega B con la coppia centrale
 * distance = distanza tra il telaio T e il cilindro A
 * angle = angolo per determinare il modo di assemblaggio del meccanismo
 * height = altezza dei cilindri
 * width = larghezza dei cilindri 
 */ 

GTdevicePressa* GTinitPressa (double l1, double l2, double l3, double distance, double angle, double height, double width);

/**
 *Controlla che i parametri permettano al meccanismo di assemblarsi correttamente.
 *Se uno dei parametri è <= 0 ritorna il codice 1
 *Se l'angolo di montaggio è minore di 0 o maggiore di 90° ritorno il codice 2
 *Se la lunghezza l3 è minore di l2 rtirona il codice 3
 *Se l1 + l2 < distanza il meccanismo non si assembla e ritorna 4
 *Se tutti i parametri sono compatibili ritorna 0 e il device viene inizializzato
 */
int CheckParam(GTdevicePressa* pressa);

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
 *
 * 
 */
string GTtoStringSGV (GTdevicePressa* pressa);



#endif 