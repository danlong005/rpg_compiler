#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string STR;
    std::string RESULT;
    STR = "Hello World"; // line 5
    RESULT = rpg_replace("RPG", STR, 7, 5); // line 8
    std::cout << RESULT << std::endl;
    RESULT = rpg_replace("Beautiful ", STR, 7); // line 12
    std::cout << RESULT << std::endl;
    RESULT = rpg_replace("Goodbye", STR, 1, 5); // line 16
    std::cout << RESULT << std::endl;
    return 0;
}
