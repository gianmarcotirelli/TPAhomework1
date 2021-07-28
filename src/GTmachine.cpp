#include "GTpressa.h"
#include "fc_scara.h"
#include "fc_svg.h"
#include "GTmachine.h"
using namespace std;

GTMachine* GTinitMachine(int thickness, int length,  int radius, int q1, int q2, int x, int y, double l1, double l2, double l3, double distance, double angleP){

    GTMachine* machine = new GTMachine;
    GTdevicePressa* Mpressa = GTinitPressa(l1, l2, l3, distance, angleP, radius * 5, radius * 3);
    int xT = 700;
    int yT = 100;  //posizione della coppia a telaio per calcolare la pos del pisotne. CONTROLLARE CHE SIANO UGUALI IN GTpressa.cpp
    int x = 700 - distance;
    int y = 100 - base/2;
    fc_scara* Mscara = fc_scara_init(thickness, length, radius, q1,  q2, x, y);
    machine->pist = Mpist;
    machine->pressa = Mpressa;
    
    //int exitCode = GTCheckParam(machine);
    int exitCode = 0;
    if (exitCode != 0) {
        cout << "Parameters violate constrais. Exitcode: " << exitCode << endl;
        delete machine;
        return NULL;
    }
    else { 
        cout << ":) " << endl; 
        return machine;
    }
}

GTMachine* GTinitMachine(GTdevicePressa* pressa, Pistone* pist){

    GTMachine* machine = new GTMachine;
    machine->pressa = pressa;
    machine->pist = pist;

    //int exitCode = GTCheckParam(machine);
    int exitCode = 0;
    if (exitCode != 0) {
        cout << "Parameters violate constrais. Exitcode: " << exitCode << endl;
        delete machine;
        return NULL;
    }
    else return machine;
}

// int GTCheckParam(GTMachine* machine){

//     if(machine == NULL) return 1;
//     else if (machine->biella->lRod > machine->pressa->l1 || machine->biella->lRod > machine->pressa->l2  || machine->biella->lRod > machine->pressa->l3) return 2;
//     else if (machine->biella->stroke > machine->pressa->l1 || machine->biella->stroke > machine->pressa->l2 || machine->biella->stroke > machine->pressa->l3) return 3;
//     else return 0;
// }

string GTtoStringMachineSVG(GTMachine* machine, bool i){

    

}


