#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string STARS(10, ' ');
    std::string DASHES(5, ' ');
    std::string PATTERN(6, ' ');
    STARS = rpg_all("*", 10); // line 7
    std::cout << STARS << std::endl;
    DASHES = rpg_all("-", 5); // line 10
    std::cout << DASHES << std::endl;
    PATTERN = rpg_all("AB", 6); // line 13
    std::cout << PATTERN << std::endl;
    return 0;
}
