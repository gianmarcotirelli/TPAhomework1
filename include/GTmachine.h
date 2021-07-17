#ifndef GTMACHINE
#define GTMACHINE

#include <iostream>
#include <cmath>
#include <string.h>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <iomanip>
#include "GTpressa.h"
// #include "LBAMTTcadSVG.h"
#include "LBAMTTdevice.h"


struct GTMachine {

    GTdevicePressa* pressa;
    LBAMTTdevice* biella;

};

GTMachine* GTinitMachine(double dShaft, double stroke, double lRod, double wRod, double hPiston, double dPiston, double angleS, double l1, double l2, double l3, double distance, double angleP);


#endif