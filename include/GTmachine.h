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
#include "fc_scara.h"
#include "fc_svg.h"


struct GTMachine {

    GTdevicePressa* pressa;
    fc_scara* scara;

};
                               //
GTMachine* GTinitMachine(int thickness, int length,  int radius, int q1, int q2, double l1, double l2, double l3, double distance, double angleP);

//GTMachine* GTinitMachine(GTdevicePressa* pressa, fc_scara* scara);

int GTCheckParam(GTMachine* machine);

string GTtoStringMachineSVG(GTMachine* machine, bool i);


#endif