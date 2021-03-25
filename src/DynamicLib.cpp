//
// Created by olli on 31/01/20.
//

#include "libdynamic/DynamicLib.h"

#include <utility>

using namespace std;

string DynamicLib::yesItsMe(int y) {
    return message + to_string(y);
}

DynamicLib::DynamicLib(string message) {
    this->message = std::move(message);
}
