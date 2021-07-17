#include "GTpressa.h"
#include "LBAMTTcadSVG.h"
#include "LBAMTTdevice.h"
using namespace std;

GTMachine* GTinitMachine(double dShaft, double stroke, double lRod, double wRod, double hPiston, double dPiston, double angleS, double l1, double l2, double l3, double distance, double angleP){

    GTMachine* machine = new GTmachine;
    machine->biella->dShaft = dShaft;

    return machine;

}

