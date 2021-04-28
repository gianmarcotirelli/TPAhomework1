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

    int exitCode = GTCheckParam(pressa);
    if (exitCode == 0) return pressa;
    else{ 
        cout << "Measures do not respect parameters constrains. Exit code: " << exitCode << endl;
        delete pressa;
        return NULL;
    }
    
}

int GTCheckParam(GTdevicePressa* pressa){

    if (pressa == NULL) return 7;
    else{
        //tutti i valori devono esse maggiori di 0
        if (pressa->l1 <= 0 || pressa->l2 <= 0 || pressa->l3 <= 0 || pressa-> distance <= 0 || pressa-> angle <= 0 || pressa->height <= 0 || pressa->width <= 0) return 1;
        else if (pressa->angle < 0.2 || pressa->angle > 0.8) return 2;
        else if (pressa->l3 < pressa-> l2) return 3;
        else if (pressa->l1 + pressa->l2 < pressa->distance) return 4;
        else if (pressa->height < pressa->width) return 5;
        else if (pressa->height > pressa->l1 / 3 || pressa->width > pressa->l1 / 5) return 6;
        else return 0;
    }
}

int GTSetL1(GTdevicePressa* pressa, double l1){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{ 
        double prev = pressa->l1;
        pressa->l1 = l1;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else 
            pressa->l1 = prev;
            cout << "Not an acceptable value" << endl;
            return 1;
    }
}


int GTSetL2(GTdevicePressa* pressa, double l2){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{
        double prev = pressa->l2;
        pressa->l2 = l2;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else 
            pressa->l2 = prev;
            cout << "Not an acceptable value" << endl;
            return 1;
    }
        
}

int GTSetL3(GTdevicePressa* pressa, double l3){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{
        double prev = pressa->l3;
        pressa->l3 = l3;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else 
            pressa->l3 = prev;
            cout << "Not an acceptable value" << endl;
            return 1;
    }
        
}

int GTSetDistance(GTdevicePressa* pressa, double distance){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{
        double prev = pressa->distance;
        pressa->distance = distance;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else 
            pressa->distance = prev;
            cout << "Not an acceptable value" << endl;
            return 1;
    }
        
}

int GTSetAngle(GTdevicePressa* pressa, double angle){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{
        double prev = pressa->angle;
        pressa->angle = angle;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else
            pressa->angle = prev;
            cout << "Not an acceptable value" << endl;
            return 1;   
    }     
}

int GTSetHeight(GTdevicePressa* pressa, double height){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{
        double prev = pressa->height;
        pressa->height = height;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else
            pressa->height = prev;
            cout << "Not an acceptable value" << endl;
            return 1;
    }       
}

int GTSetWidth(GTdevicePressa* pressa, double width){

    if(pressa == NULL){
        cout << "Device does not exist" << endl;
        return 2;
    }
    else{
        double prev = pressa->width;
        pressa->width = width;
        int exitCode = GTCheckParam(pressa);
        if (exitCode == 0) return 0;
        else
            pressa->width = prev;
            cout << "Not an acceptable value" << endl;
            return 1;
    }
}

string GTtoStringSGV (GTdevicePressa* pressa){

    if(pressa == NULL){
        return "Device does not exist. \n";
    }
    else{
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
        
        s += "<!DOCTYPE html> \n <html> \n <body> \n <svg height=\""+to_string(pressa->l1 + pressa->l2 + 100)+"\""; 
        s += " width=\""+to_string(pressa->l2 + pressa->l3 + 100)+"\"> \n"; 

        //Coppia a telaio T e coppia centrale C
        s += "<circle cx=\""+to_string(xT)+"\" cy=\""+ to_string(yT)+"\"r=\""+ to_string(r)+"\" stroke=\"black\" stroke-width=\"3\" fill=\"red\"/> \n";  //T
        s += "<circle cx=\""+to_string(xC)+"\" cy=\""+to_string(yC)+" \"r=\""+ to_string(r)+"\" stroke=\"black\" stroke-width=\"3\" fill=\"white\"/> \n\n";  // C

        //Cilindro A e telaio
        s += "<rect width=\""+to_string(pressa->width)+"\" height=\""+to_string(pressa->height)+"\"";  
        s += "transform=\"translate("+to_string(xA - (pressa->width * 0.5))+" ,"+to_string(yA - (pressa->height * 0.5))+")\" /> \n";  //traslazione di A
        s += "<circle cx=\""+to_string(xA)+"\" cy=\""+to_string(yA)+"\" r=\""+to_string(r)+"\" stroke=\"black\" stroke-width=\"3\" fill=\"white\" />\" \n"; // coppia in A
        s += "<line x1=\""+to_string(xA - (pressa->width * 0.5))+"\" y1=\""+to_string(yA - (pressa->height))+"\" x2=\""+to_string(xA - (pressa->width * 0.5))+"\" y2=\""+to_string(yA + (pressa->height))+"\"";
        s += " style=\"stroke:rgb(255,0,0);stroke-width:2\"/> \n\n";

        //Cilindro B e telaio
        s += "<rect width=\""+to_string(pressa->height)+"\" height=\""+to_string(pressa->width)+"\"";
        s += "transform=\"translate("+to_string(xB - (pressa->height * 0.5))+","+to_string(yB - (pressa->width * 0.5))+")\" /> \n";
        s += "<circle cx=\""+to_string(xB)+"\" cy=\""+to_string(yB)+"\" r=\""+to_string(r)+"\" stroke=\"black\" stroke-width=\"3\" fill=\"white\"/> \n";
        s += "<line x1=\""+to_string(xB - (pressa->height * 0.5))+"\" y1=\""+to_string(yB - pressa->height)+"\" x2=\""+to_string(xB - (pressa->height * 0.5))+"\" y2=\""+to_string(yB + pressa->height)+"\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/> \n";
        s += "<line x1=\""+to_string(xB + (pressa->height * 0.5))+"\" y1=\""+to_string(yB - pressa->height)+"\" x2=\""+to_string(xB + (pressa->height * 0.5))+"\" y2=\""+to_string(yB + pressa->height)+"\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/> \n\n";

        //Aste di collegamento
        s += "<line x1=\""+to_string(xA)+"\" y1=\""+to_string(yA)+"\" x2=\""+to_string(xC)+"\" y2=\""+to_string(yC)+"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/> \n";
        s += "<line x1=\""+to_string(xB)+"\" y1=\""+to_string(yB)+"\" x2=\""+to_string(xC)+"\" y2=\""+to_string(yC)+"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/> \n";
        s += "<line x1=\""+to_string(xT)+"\" y1=\""+to_string(yT)+"\" x2=\""+to_string(xC)+"\" y2=\""+to_string(yC)+"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/> \n\n";

        s += "</svg> \n\n </body>\n\n </html> \n";

        return s; 
    } 
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

void GTDeleteDevice(GTdevicePressa* pressa){

    if(pressa == NULL){
        cout << "Device does not exist or it is already been deleted" << endl;
    }
    else{
        delete pressa;
        pressa = NULL;
    }
}




