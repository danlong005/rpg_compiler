#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string shared_msg = "From copybook";
    const auto _init_shared_msg = shared_msg;
    int shared_val = 99;
    const auto _init_shared_val = shared_val;
    int local_val = 0;
    local_val = (shared_val + 1); // line 7
    std::cout << shared_msg << std::endl;
    std::cout << rpg_to_char(local_val) << std::endl;
    return 0;
}
