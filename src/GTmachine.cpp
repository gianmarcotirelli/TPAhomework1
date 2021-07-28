#include "../include/GTpressa.h"
#include "../include/fc_scara.h"
#include "../include/fc_svg.h"
#include "../include/GTmachine.h"
using namespace std;

GTMachine* GTinitMachine(int thickness, int length,  int radius, int q1, int q2, double l1, double l2, double l3, double distance, double angleP){

    GTMachine* machine = new GTMachine;

    GTdevicePressa* Mpressa = GTinitPressa(l1, l2, l3, distance, angleP, radius * 8, radius * 3);

    double a = 4.71 - (q1 * 3.14 / 180); //angolo tra il primo braccio e la verticale 
    double b = 6.28 - (3.14 - 1.57 - a) - (q2 * 3.14/180); 
    double x = GTgetxA(Mpressa);
    double y = GTgetyA(Mpressa) - (length * sin(b)) - (length * cos(a));
    fc_scara* Mscara = fc_scara_init(thickness, length, radius, q1,  q2, x, y);

    machine->scara = Mscara;
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

// GTMachine* GTinitMachine(GTdevicePressa* pressa, fc_scara* scara){

//     GTMachine* machine = new GTMachine;
//     machine->pressa = pressa;
//     machine->scara = scara;

//     //int exitCode = GTCheckParam(machine);
//     int exitCode = 0;
//     if (exitCode != 0) {
//         cout << "Parameters violate constrais. Exitcode: " << exitCode << endl;
//         delete machine;
//         return NULL;
//     }
//     else return machine;
// }

// int GTCheckParam(GTMachine* machine){

//     if(machine == NULL) return 1;
//     else if (machine->biella->lRod > machine->pressa->l1 || machine->biella->lRod > machine->pressa->l2  || machine->biella->lRod > machine->pressa->l3) return 2;
//     else if (machine->biella->stroke > machine->pressa->l1 || machine->biella->stroke > machine->pressa->l2 || machine->biella->stroke > machine->pressa->l3) return 3;
//     else return 0;
// }

string GTtoStringMachineSVG(GTMachine* machine, bool i){

    string s;
    s = fc_scara_to_svg(machine->scara);
    s += GTtoStringSGV(machine->pressa, i);
    return s;
}


