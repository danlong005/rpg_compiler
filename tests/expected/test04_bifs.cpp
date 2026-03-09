#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string PADDED(20, ' ');
    std::string TRIMMED;
    int LENGTH = 0;
    std::string PART;
    PADDED = "  Hello  "; // line 6
    TRIMMED = rpg_trim(PADDED); // line 7
    std::cout << TRIMMED << std::endl;
    TRIMMED = rpg_triml(PADDED); // line 9
    std::cout << TRIMMED << std::endl;
    TRIMMED = rpg_trimr(PADDED); // line 11
    std::cout << TRIMMED << std::endl;
    LENGTH = static_cast<int>(PADDED.size()); // line 13
    std::cout << rpg_to_char(LENGTH) << std::endl;
    PART = PADDED.substr(3 - 1, 5); // line 15
    std::cout << PART << std::endl;
    return 0;
}
