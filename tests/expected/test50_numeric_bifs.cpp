#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    double val = 0.0;
    int result = 0;
    int uval = 0;
    int dpos = 0;
    val = 3.456; // line 8
    result = static_cast<int>(std::round(static_cast<double>(val))); // line 11
    std::cout << rpg_to_char(result) << std::endl;
    val = rpg_dech(3.456, 1); // line 15
    std::cout << rpg_to_char(val) << std::endl;
    dpos = rpg_decpos(val); // line 19
    std::cout << rpg_to_char(dpos) << std::endl;
    uval = static_cast<unsigned int>(42); // line 23
    std::cout << rpg_to_char(uval) << std::endl;
    return 0;
}
