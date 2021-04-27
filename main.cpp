#include "include/GTpressa.h"
#include <iostream>
using namespace std;

int main() {

    GTdevicePressa* dev = GTinitPressa(100, 100, 100, 80, 0.5, 300, 10);

    string code = GTtoStringSGV(dev);
    string name = "provaSaveLoad";
    GTSaveToFile(code, name);
    cout << "ecco il codice caricato: " << endl << GTLoadFromFile(name);

    return 0;
};
