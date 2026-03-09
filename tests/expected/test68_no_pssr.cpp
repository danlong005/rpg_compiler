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
    std::cout << "Before error" << std::endl;
    MYDATE = rpg_make_date("2024-01-15"); // line 8
    BADDATE = rpg_make_date("not-a-date"); // line 9
    DIFF = rpg_diff_days(BADDATE, MYDATE); // line 10
    std::cout << "After error" << std::endl;
    return 0;
}
