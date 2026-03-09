#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    double num1 = 0.0;
    double num2 = 0.0;
    std::string result;
    num1 = 12345.67; // line 6
    num2 = (0 - 1234.56); // line 7
    result = rpg_editc(num1, "1"); // line 10
    std::cout << result << std::endl;
    result = rpg_editc(num1, "2"); // line 14
    std::cout << result << std::endl;
    result = rpg_editc(num2, "3"); // line 18
    std::cout << result << std::endl;
    result = rpg_editc(num2, "4"); // line 22
    std::cout << result << std::endl;
    result = rpg_editc(num1, "X"); // line 26
    std::cout << result << std::endl;
    result = rpg_editw(num1, "  ,   .  "); // line 30
    std::cout << result << std::endl;
    return 0;
}
