#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string padded(20, ' ');
    std::string trimmed;
    int length = 0;
    std::string part;
    padded = "  Hello  "; // line 6
    trimmed = rpg_trim(padded); // line 7
    std::cout << trimmed << std::endl;
    trimmed = rpg_triml(padded); // line 9
    std::cout << trimmed << std::endl;
    trimmed = rpg_trimr(padded); // line 11
    std::cout << trimmed << std::endl;
    length = static_cast<int>(padded.size()); // line 13
    std::cout << rpg_to_char(length) << std::endl;
    part = padded.substr(3 - 1, 5); // line 15
    std::cout << part << std::endl;
    return 0;
}
