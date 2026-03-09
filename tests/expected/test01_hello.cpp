#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string GREETING(20, ' ');
    int COUNT = 0;
    GREETING = "Hello, world!"; // line 4
    COUNT = 42; // line 5
    std::cout << GREETING << std::endl;
    std::cout << rpg_to_char(COUNT) << std::endl;
    return 0;
}
