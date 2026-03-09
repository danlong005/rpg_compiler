#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int x = 0;
    int y = 0;
    x = 10; // line 4
    y = 20; // line 6
    std::cout << rpg_to_char(x) << std::endl;
    std::cout << rpg_to_char(y) << std::endl;
    return 0;
}
