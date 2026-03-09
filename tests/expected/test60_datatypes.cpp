#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    unsigned int uval = 0;
    double fval = 0.0;
    int bval = 0;
    uval = 42; // line 7
    std::cout << rpg_to_char(uval) << std::endl;
    fval = 3.14159; // line 10
    std::cout << rpg_to_char(fval) << std::endl;
    bval = 100; // line 13
    std::cout << rpg_to_char(bval) << std::endl;
    uval = static_cast<unsigned int>(99); // line 17
    std::cout << rpg_to_char(uval) << std::endl;
    fval = static_cast<double>(42); // line 21
    std::cout << rpg_to_char(fval) << std::endl;
    return 0;
}
