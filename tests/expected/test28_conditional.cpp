#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string MSG;
    MSG = "Greeting enabled"; // line 8
    std::cout << MSG << std::endl;
    MSG = "Not defined works"; // line 18
    std::cout << MSG << std::endl;
    MSG = "Debug on"; // line 23
    std::cout << MSG << std::endl;
    MSG = "Undef worked"; // line 37
    std::cout << MSG << std::endl;
    return 0;
}
