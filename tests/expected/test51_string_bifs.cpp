#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string str;
    std::string left;
    std::string right;
    std::string result;
    std::string names;
    str = "Hello World"; // line 7
    left = str.substr(0, 5); // line 10
    std::cout << left << std::endl;
    right = rpg_right(str, 5); // line 14
    std::cout << right << std::endl;
    names = "Alice,Bob,Charlie"; // line 20
    result = names; // line 21
    std::cout << result << std::endl;
    return 0;
}
