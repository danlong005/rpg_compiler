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
    A = 10; // line 5
    B = 3; // line 6
    RESULT = (A + B); // line 7
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = (A - B); // line 9
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = (A * B); // line 11
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = (A / B); // line 13
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = ((A + B) * 2); // line 15
    std::cout << rpg_to_char(RESULT) << std::endl;
    return 0;
}
