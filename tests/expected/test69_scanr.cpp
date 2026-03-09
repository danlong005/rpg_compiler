#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int POS = 0;
    std::string TEXT;
    TEXT = "Hello World Hello"; // line 5
    POS = rpg_scanr("Hello", TEXT); // line 8
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_scanr("o", TEXT); // line 12
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_scanr("xyz", TEXT); // line 16
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_scanr("Hello", TEXT, 10); // line 20
    std::cout << rpg_to_char(POS) << std::endl;
    return 0;
}
