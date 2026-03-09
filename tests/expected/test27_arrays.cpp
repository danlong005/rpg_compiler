#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::array<int, 5> NUMBERS;
    std::array<std::string, 3> NAMES;
    int I = 0;
    int TOTAL = 0;
    int COUNT = 0;
    NUMBERS[1 - 1] = 10; // line 9
    NUMBERS[2 - 1] = 20; // line 10
    NUMBERS[3 - 1] = 30; // line 11
    NUMBERS[4 - 1] = 40; // line 12
    NUMBERS[5 - 1] = 50; // line 13
    TOTAL = 0; // line 16
    for (I = 1; I <= 5; I += 1) {
        TOTAL = (TOTAL + NUMBERS[I - 1]); // line 18
    }
    std::cout << rpg_to_char(TOTAL) << std::endl;
    COUNT = static_cast<int>(NUMBERS.size()); // line 23
    std::cout << rpg_to_char(COUNT) << std::endl;
    NAMES[1 - 1] = "Alice"; // line 27
    NAMES[2 - 1] = "Bob"; // line 28
    NAMES[3 - 1] = "Charlie"; // line 29
    for (I = 1; I <= static_cast<int>(NAMES.size()); I += 1) {
        std::cout << NAMES[I - 1] << std::endl;
    }
    NUMBERS[3 - 1] = 99; // line 36
    std::cout << rpg_to_char(NUMBERS[3 - 1]) << std::endl;
    return 0;
}
