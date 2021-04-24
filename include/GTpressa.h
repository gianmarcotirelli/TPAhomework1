#ifndef GTPRESSA_H
#define GTPRESSA_H

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

struct GTdevicepressa {
    double l1;
    double l2;
    double l3;
    double distance;
    double height;
    double width;
};

GTdevicepressa* GTinitPressa (double l1, double l2, double l3, double distance, double height, double width)

#endif 