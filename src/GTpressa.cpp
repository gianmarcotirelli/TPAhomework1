#include "../include/GTpressa.h"
using namespace std;


GTdevicePressa* GTinitPressa (double l1, double l2, double l3, double distance, double angle, double height, double width){

    GTdevicePressa* pressa = new GTdevicePressa;

    pressa->l1 = l1;
    pressa->l2 = l2;
    pressa->l3 = l3;
    pressa->distance = distance;
    pressa->angle = angle;
    pressa->height = height;
    pressa->width = width;

    if (CheckParam(pressa)) return pressa;
    else 
        delete pressa;
        return NULL;
    
}

int CheckParam(GTdevicePressa* pressa){

    //tutti i valori devono esse maggiori di 0
    if (pressa->l1 < 0 || pressa->l2 < 0 || pressa->l3 < 0 || pressa-> distance < 0 || pressa-> angle < 0 || pressa->height < 0 || pressa->width < 0) return 1;
    else if (pressa->angle < 0 || pressa->angle > 1.57) return 2;
    else if (pressa->l3 <= pressa-> l2) return 3;
    else if (pressa->l1 + pressa->l2 < pressa->distance) return 4;
    else return 0;
}

int GTSetL1(GTdevicePressa* pressa, double l1){
    double prev = pressa->l1;
    pressa->l1 = l1;
    if (CheckParam(pressa)) return 0;
    else 
        pressa->l1 = prev;
        return 1;
        
}

int GTSetL2(GTdevicePressa* pressa, double l2){
    double prev = pressa->l2;
    pressa->l2 = l2;
    if (CheckParam(pressa)) return 0;
    else 
        pressa->l2 = prev;
        return 1;
        
}

int GTSetL3(GTdevicePressa* pressa, double l3){
    double prev = pressa->l3;
    pressa->l3 = l3;
    if (CheckParam(pressa)) return 0;
    else 
        pressa->l3 = prev;
        return 1;
        
}

int GTSetDistance(GTdevicePressa* pressa, double distance){
    double prev = pressa->distance;
    pressa->distance = distance;
    if (CheckParam(pressa)) return 0;
    else 
        pressa->distance = prev;
        return 1;
        
}

int GTSetAngle(GTdevicePressa* pressa, double angle){
    double prev = pressa->angle;
    pressa->angle = angle;
    if (CheckParam(pressa)) return 0;
    else
        pressa->angle = prev;
        return 1;        
}

int GTSetHeight(GTdevicePressa* pressa, double height){
    double prev = pressa->height;
    pressa->height = height;
    if (CheckParam(pressa)) return 0;
    else
        pressa->height = prev;
        return 1;       
}

int GTSetWidth(GTdevicePressa* pressa, double width){
    double prev = pressa->width;
    pressa->width = width;
    if (CheckParam(pressa)) return 0;
    else
        pressa->width = prev;
        return 1;
}

string GTtoStringSGV (GTdevicePressa* pressa){

    double xT = pressa->l1; //Posizione della coppia rotoidale T. Valori casuali
    double yT = pressa->l2;
    double r = pressa->width/3;
    double a = pressa->angle; //per comodità
    string s = "";

    double xC = xT - pressa->l2 * sin(a);
    double yC = yT + pressa->l2 * cos(a);

    double xB = xT;
    double yB = yC + sqrt(pow(pressa->l3 , 2) - pow(xB - xC , 2));

    double xA = xT - pressa->distance;
    double yA = yC - sqrt(pow(pressa->l1 , 2) - (xT - xC , 2));
    
    s += "<!DOCTYPE html> \n <html> \n <body> \n <svg height=\""+to_string(pressa->l1 + pressa->l2 + pressa->height)+""; 
    s += "width=\""+ to_string(pressa->l2 + pressa->l3 + pressa->height)+" \"> \n"; 

    //Coppia a telaio T e coppia centrale C
    s += "<circle cx=\" " + to_string(xT) + "\" y=\" " + to_string(yT)+ "\"r=\" " + to_string(r) + " \" stroke=\"black\" stroke-width=\"3\" fill=\"red\"/> \n";  //T
    s += "<circle cx=\" "+to_string(xC)+" \" cy=\" "+to_string(yC)+" \" r=\"10\" stroke=\"black\" stroke-width=\"3\" fill=\"white\"> \n";  // C

    //Cilindro A e telaio
    s += "<rect width=\" "+to_string(pressa->width)+" \" height=\" "+to_string(pressa->height)+" \"";  
    s += "transform=\"translate( "+to_string(xA - (pressa->width * 0.5))+" ,"+to_string(yA - (pressa->height * 0.5))+")\" /> \n";  //traslazione di A
    s += "<circle cx=\" "+to_string(xA)+" \" cy=\""+to_string(yA)+"\" r=\" "+to_string(r)+" \" stroke=\"black\" stroke-width=\"3\" fill=\"white\" />\" \n"; // coppia in A
    s += "<line x1=\""+to_string(xA - (pressa->width * 0.5))+"\" y1=\""+to_string(yA - (pressa->height))+"\" x2=\""+to_string(xA - (pressa->width * 0.5))+"\" y2=\""+to_string(yA + (pressa->height))+" \"";
    s += " style=\"stroke:rgb(255,0,0);stroke-width:2\"/> \n";

    //Cilindro B e telaio
    s += "<rect width=\" "+to_string(pressa->height)+" \" height=\" "+to_string(pressa->width)+" \"";
    s += "transform=\"translate("+to_string(xC - (pressa->height * 0.5))+","+to_string(yC - (pressa->width * 0.5))+") rotate(90)\" /> \n";
    s += "<circle cx=\""+to_string(xB)+"\" cy=\""+to_string(yB)+"\" r=\""+to_string(r)+"\" stroke=\"black\" stroke-width=\"3\" fill=\"white\"/> \n";
    s += "<line x1=\""+to_string(xC - (pressa->height * 0.5))+"\" y1=\""+to_string(yC - pressa->width)+"\" x2=\""+to_string(xC - (pressa->height * 0.5))+"\" y2=\""+to_string(yC - pressa->height)+"\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/> \n";
    s += "<line x1=\""+to_string(xC + (pressa->height * 0.5))+"\" y1=\""+to_string(yC + pressa->width)+"\" x2=\""+to_string(xC + (pressa->height * 0.5))+"\" y2=\""+to_string(yC + pressa->height)+"\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/> \n";

    //Aste di collegamento
    s += "<line x1=\""+to_string(xA)+"\" y1=\""+to_string(yA)+"\" x2=\""+to_string(xC)+"\" y2=\""+to_string(xC)+"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/> \n";
    s += "<line x1=\""+to_string(xB)+"\" y1=\""+to_string(yB)+"\" x2=\""+to_string(xC)+"\" y2=\""+to_string(xC)+"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/> \n";
    s += "<line x1=\""+to_string(xT)+"\" y1=\""+to_string(yT)+"\" x2=\""+to_string(xC)+"\" y2=\""+to_string(xC)+"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/> \n";

    s += "</svg> \n\n </body>\n\n </html>";

    return s;  
}

void GTSaveToFile(string s, string name){

    //creating a new file
    ofstream code (name);
    code << s << endl;
    code.close();
}


string GTLoadFromFile (string name){

    ifstream code(name);
    stringstream buffer;
    buffer << code.rdbuf();
    string s = buffer.str();
    return s;

}



