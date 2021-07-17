#include "include/GTpressa.h"
#include <iostream>
using namespace std;

int main() {

    GTdevicePressa* dev = GTinitPressa(200, 200, 200, 200, 0.3 , 60, 20);

    string code = GTtoStringSGV(dev, 1);
    cout << endl << code << endl;
    

    return 0;
};
