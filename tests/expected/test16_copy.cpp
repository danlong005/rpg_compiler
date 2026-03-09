#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string SHARED_MSG = "From copybook";
    const auto _init_SHARED_MSG = SHARED_MSG;
    int SHARED_VAL = 99;
    const auto _init_SHARED_VAL = SHARED_VAL;
    int LOCAL_VAL = 0;
    LOCAL_VAL = (SHARED_VAL + 1); // line 7
    std::cout << SHARED_MSG << std::endl;
    std::cout << rpg_to_char(LOCAL_VAL) << std::endl;
    return 0;
}
