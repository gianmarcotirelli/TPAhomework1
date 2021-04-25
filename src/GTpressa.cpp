#include "GTpressa.h"

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
    else if {
        delete pressa;
        return NULL;
    };
};

int CheckParam(GTdevicePressa* pressa){

    //tutti i valori devono esse maggiori di 0
    if (pressa->l1 < 0 || pressa->l2 < 0 || pressa->l3 < 0 || pressa-> distance < 0 || pressa-> angle < 0 || pressa->height < 0 || pressa->widht < 0) return 1;
    else if (pressa->angle < 0 || pressa->angle > 1.57) return 2;
    else if (pressa->l3 <= pressa-> l2) return 3;
    else if (pressa->l1 + pressa->l2 < pressa->distance) return 4;
    else return 0
};

int GTSetL1(GTdevicePressa* pressa, double l1){
    double prev = pressa->l1;
    pressa->l1 = l1;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->l1 = prev
        return 1:
        };
};

int GTSetL2(GTdevicePressa* pressa, double l2){
    double prev = pressa->l2;
    pressa->l2 = l2;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->l2 = prev
        return 1:
        };
};

int GTSetL3(GTdevicePressa* pressa, double l3){
    double prev = pressa->l3;
    pressa->l3 = l3;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->l3 = prev
        return 1:
        };
};

int GTSetDistance(GTdevicePressa* pressa, double distance){
    double prev = pressa->distance;
    pressa->distance = distance;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->distance = prev
        return 1:
        };
};

int GTSetAngle(GTdevicePressa* pressa, double angle){
    double prev = pressa->angle;
    pressa->angle = angle;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->angle = prev
        return 1:
        };
};

int GTSetHeight(GTdevicePressa* pressa, double height){
    double prev = pressa->height;
    pressa->height = height;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->height = prev
        return 1:
        };
};

int GTSetWidth(GTdevicePressa* pressa, double width){
    double prev = pressa->width;
    pressa->width = width;
    if (CheckParam(pressa)) return 0;
    else {
        pressa->width = prev
        return 1:
        };
};

string GTtoStringSGV (GTdevicePressa* pressa){

    double xT = pressa->l1; //Posizione della coppia rotoidale T. Valori casuali
    double yT = pressa->l2;
    double a = pressa->angle; //per comodità
    string s = "";

    double xC = xT - pressa->l2 Sin(a);
    double yC = yT + pressa->l2 Cos(a);

    double xB = xT;
    double yB = yC + sqrt(pow(pressa->l3 , 2) - pow(xB - xC , 2));

    double xA = xT - pressa->distance;
    double yA = yC - sqrt(pow(pressa->l1 , 2) - (xT - xC , 2));

};

