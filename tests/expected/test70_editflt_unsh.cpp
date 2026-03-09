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
    int RESULT = 0;
    TEXT = rpg_editflt(1234.5); // line 6
    std::cout << TEXT << std::endl;
    TEXT = rpg_editflt((0 - 0.005)); // line 9
    std::cout << TEXT << std::endl;
    RESULT = rpg_unsh(3.7); // line 13
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = rpg_unsh(3.2); // line 16
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = rpg_unsh(5.5); // line 19
    std::cout << rpg_to_char(RESULT) << std::endl;
    return 0;
}
