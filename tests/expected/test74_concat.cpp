#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string RESULT;
    std::string NAME;
    std::string CITY;
    std::string STATE;
    NAME = "Alice"; // line 7
    CITY = "Dallas"; // line 8
    STATE = "TX"; // line 9
    RESULT = rpg_concat(", ", NAME, CITY, STATE); // line 12
    std::cout << RESULT << std::endl;
    RESULT = rpg_concat("-", "2024", "03", "15"); // line 16
    std::cout << RESULT << std::endl;
    RESULT = rpg_concat(" ", "Hello", "World"); // line 20
    std::cout << RESULT << std::endl;
    RESULT = rpg_concat("", "A", "B", "C"); // line 24
    std::cout << RESULT << std::endl;
    return 0;
}
