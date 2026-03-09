#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    double NUM1 = 0.0;
    double NUM2 = 0.0;
    std::string RESULT;
    NUM1 = 12345.67; // line 6
    NUM2 = (0 - 1234.56); // line 7
    RESULT = rpg_editc(NUM1, "1"); // line 10
    std::cout << RESULT << std::endl;
    RESULT = rpg_editc(NUM1, "2"); // line 14
    std::cout << RESULT << std::endl;
    RESULT = rpg_editc(NUM2, "3"); // line 18
    std::cout << RESULT << std::endl;
    RESULT = rpg_editc(NUM2, "4"); // line 22
    std::cout << RESULT << std::endl;
    RESULT = rpg_editc(NUM1, "X"); // line 26
    std::cout << RESULT << std::endl;
    RESULT = rpg_editw(NUM1, "  ,   .  "); // line 30
    std::cout << RESULT << std::endl;
    return 0;
}
