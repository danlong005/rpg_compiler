#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string ERRMSG;
    RpgDate MYDATE;
    RpgDate BADDATE;
    int DIFF = 0;
    auto sr__PSSR = [&]() {
        ERRMSG = "Error caught by *PSSR"; // line 8
        std::cout << ERRMSG << std::endl;
    };
    try {
        std::cout << "Before error" << std::endl;
        MYDATE = rpg_make_date("2024-01-15"); // line 13
        BADDATE = rpg_make_date("not-a-date"); // line 14
        DIFF = rpg_diff_days(BADDATE, MYDATE); // line 15
        std::cout << "After error" << std::endl;
        return 0;
    } catch (...) {
        sr__PSSR();
    }
}
