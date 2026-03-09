#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string str;
    int pos = 0;
    str = "  Hello"; // line 5
    pos = rpg_check(" ", str); // line 9
    std::cout << rpg_to_char(pos) << std::endl;
    pos = rpg_check("Helo", str, 3); // line 13
    std::cout << rpg_to_char(pos) << std::endl;
    pos = rpg_check("Helo ", str); // line 17
    std::cout << rpg_to_char(pos) << std::endl;
    str = "Hello   "; // line 21
    pos = rpg_checkr(" ", str); // line 22
    std::cout << rpg_to_char(pos) << std::endl;
    return 0;
}
