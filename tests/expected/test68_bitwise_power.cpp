#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int A = 0;
    int B = 0;
    int RESULT = 0;
    double FLOATRESULT = 0.0;
    A = 15; // line 8
    B = 9; // line 9
    RESULT = (static_cast<unsigned int>(A) & static_cast<unsigned int>(B)); // line 10
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = (static_cast<unsigned int>(A) | static_cast<unsigned int>(B)); // line 14
    std::cout << rpg_to_char(RESULT) << std::endl;
    A = 12; // line 18
    B = 10; // line 19
    RESULT = (static_cast<unsigned int>(A) ^ static_cast<unsigned int>(B)); // line 20
    std::cout << rpg_to_char(RESULT) << std::endl;
    A = 0; // line 24
    RESULT = (static_cast<unsigned int>((~static_cast<unsigned int>(A))) & static_cast<unsigned int>(255)); // line 25
    std::cout << rpg_to_char(RESULT) << std::endl;
    FLOATRESULT = std::pow(2, 10); // line 29
    std::cout << rpg_to_char(FLOATRESULT) << std::endl;
    FLOATRESULT = std::pow(3, 3); // line 32
    std::cout << rpg_to_char(FLOATRESULT) << std::endl;
    return 0;
}
