#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int X = 0;
    std::string MSG(20, ' ');
    X = 42; // line 4
    MSG = "No FREE needed"; // line 5
    std::cout << MSG << std::endl;
    std::cout << rpg_to_char(X) << std::endl;
    return 0;
}
