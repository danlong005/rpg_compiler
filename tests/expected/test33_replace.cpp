#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string str;
    std::string result;
    str = "Hello World"; // line 5
    result = rpg_replace("RPG", str, 7, 5); // line 8
    std::cout << result << std::endl;
    result = rpg_replace("Beautiful ", str, 7); // line 12
    std::cout << result << std::endl;
    result = rpg_replace("Goodbye", str, 1, 5); // line 16
    std::cout << result << std::endl;
    return 0;
}
