#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    unsigned int UVAL = 0;
    double FVAL = 0.0;
    int BVAL = 0;
    UVAL = 42; // line 7
    std::cout << rpg_to_char(UVAL) << std::endl;
    FVAL = 3.14159; // line 10
    std::cout << rpg_to_char(FVAL) << std::endl;
    BVAL = 100; // line 13
    std::cout << rpg_to_char(BVAL) << std::endl;
    UVAL = static_cast<unsigned int>(99); // line 17
    std::cout << rpg_to_char(UVAL) << std::endl;
    FVAL = static_cast<double>(42); // line 21
    std::cout << rpg_to_char(FVAL) << std::endl;
    return 0;
}
