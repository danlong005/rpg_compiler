#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string stars(10, ' ');
    std::string dashes(5, ' ');
    std::string pattern(6, ' ');
    stars = rpg_all("*", 10); // line 7
    std::cout << stars << std::endl;
    dashes = rpg_all("-", 5); // line 10
    std::cout << dashes << std::endl;
    pattern = rpg_all("AB", 6); // line 13
    std::cout << pattern << std::endl;
    return 0;
}
