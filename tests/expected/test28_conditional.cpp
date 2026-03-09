#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string msg;
    msg = "Greeting enabled"; // line 8
    std::cout << msg << std::endl;
    msg = "Not defined works"; // line 18
    std::cout << msg << std::endl;
    msg = "Debug on"; // line 23
    std::cout << msg << std::endl;
    msg = "Undef worked"; // line 37
    std::cout << msg << std::endl;
    return 0;
}
