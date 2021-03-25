/*
 * Header for example class part of a dynamic library
 */

#ifndef STRUCTURE_DYNAMICLIB_H
#define STRUCTURE_DYNAMICLIB_H

#include <string>

using namespace std;

class DynamicLib {
private:
    string message;

public:
    explicit DynamicLib(string message);

    string yesItsMe(int y);
};


#endif //STRUCTURE_DYNAMICLIB_H
