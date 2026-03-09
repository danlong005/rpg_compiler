#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    double VAL = 0.0;
    int RESULT = 0;
    int UVAL = 0;
    int DPOS = 0;
    VAL = 3.456; // line 8
    RESULT = static_cast<int>(std::round(static_cast<double>(VAL))); // line 11
    std::cout << rpg_to_char(RESULT) << std::endl;
    VAL = rpg_dech(3.456, 1); // line 15
    std::cout << rpg_to_char(VAL) << std::endl;
    DPOS = rpg_decpos(VAL); // line 19
    std::cout << rpg_to_char(DPOS) << std::endl;
    UVAL = static_cast<unsigned int>(42); // line 23
    std::cout << rpg_to_char(UVAL) << std::endl;
    return 0;
}
