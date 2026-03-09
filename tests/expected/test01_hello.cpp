#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string greeting(20, ' ');
    int count = 0;
    greeting = "Hello, world!"; // line 4
    count = 42; // line 5
    std::cout << greeting << std::endl;
    std::cout << rpg_to_char(count) << std::endl;
    return 0;
}
