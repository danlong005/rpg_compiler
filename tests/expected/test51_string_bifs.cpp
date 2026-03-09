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
    std::string LEFT;
    std::string RIGHT;
    std::string RESULT;
    std::string NAMES;
    STR = "Hello World"; // line 7
    LEFT = STR.substr(0, 5); // line 10
    std::cout << LEFT << std::endl;
    RIGHT = rpg_right(STR, 5); // line 14
    std::cout << RIGHT << std::endl;
    NAMES = "Alice,Bob,Charlie"; // line 20
    RESULT = NAMES; // line 21
    std::cout << RESULT << std::endl;
    return 0;
}
