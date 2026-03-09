#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string TEXT;
    int POS = 0;
    std::string RESULT;
    std::string UPPER;
    double NUM = 0.0;
    int WHOLE = 0;
    TEXT = "Hello World"; // line 10
    POS = rpg_scan("World", TEXT); // line 11
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_scan("xyz", TEXT); // line 14
    std::cout << rpg_to_char(POS) << std::endl;
    RESULT = rpg_scanrpl("World", "RPG", TEXT); // line 18
    std::cout << RESULT << std::endl;
    UPPER = rpg_xlate("abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", TEXT); // line 22
    std::cout << UPPER << std::endl;
    NUM = 42.75; // line 26
    WHOLE = static_cast<int>(NUM); // line 27
    std::cout << rpg_to_char(WHOLE) << std::endl;
    NUM = static_cast<double>(WHOLE); // line 30
    std::cout << rpg_to_char(NUM) << std::endl;
    RESULT = TEXT.substr(1 - 1, 5); // line 34
    std::cout << RESULT << std::endl;
    return 0;
}
