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
    int POS = 0;
    STR = "  Hello"; // line 5
    POS = rpg_check(" ", STR); // line 9
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_check("Helo", STR, 3); // line 13
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_check("Helo ", STR); // line 17
    std::cout << rpg_to_char(POS) << std::endl;
    STR = "Hello   "; // line 21
    POS = rpg_checkr(" ", STR); // line 22
    std::cout << rpg_to_char(POS) << std::endl;
    return 0;
}
