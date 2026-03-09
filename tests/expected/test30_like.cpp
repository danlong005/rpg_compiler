#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int baseInt = 0;
    std::string baseStr;
    double baseDec = 0.0;
    int copyInt = 0;
    std::string copyStr;
    double copyDec = 0.0;
    baseInt = 42; // line 11
    copyInt = baseInt; // line 12
    std::cout << rpg_to_char(copyInt) << std::endl;
    baseStr = "Hello LIKE"; // line 15
    copyStr = baseStr; // line 16
    std::cout << copyStr << std::endl;
    baseDec = 3.14; // line 19
    copyDec = baseDec; // line 20
    std::cout << rpg_to_char(copyDec) << std::endl;
    return 0;
}
