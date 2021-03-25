#include <iostream>

#include "funcs.h"
#include "A.h"
#include "libstatic/StaticLib.h"
#include "libdynamic/DynamicLib.h"
#include "libtemplate/Template.h"

using namespace std;

int main() {

    cout << "Funcs: " << foo(9) << endl;

    A::yes(42);

    StaticLib sl(90);
    cout << "Static: " << sl.testMe(6) << endl;

    DynamicLib dl("Dynamic: ");
    cout << dl.yesItsMe(50) << endl;

    TemplateLib<int> tl(44);
    cout << "Template: " << tl.getStuff() << endl;

    return 0;
}
