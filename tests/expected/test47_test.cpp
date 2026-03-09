#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    RpgDate MYDATE;
    bool VALID = false;
    MYDATE = rpg_make_date("2024-03-15"); // line 6
    rpg_error_flag() = !rpg_test_date(MYDATE);
    VALID = !(rpg_error()); // line 8
    if (VALID) {
        std::cout << "Date valid" << std::endl;
    }
    std::cout << "Test done" << std::endl;
    return 0;
}
