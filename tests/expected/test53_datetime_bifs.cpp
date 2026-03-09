#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    RpgTime t1;
    RpgTime t2;
    int diff = 0;
    int hr = 0;
    int mn = 0;
    t1 = rpg_make_time("14:30:00"); // line 9
    t2 = rpg_make_time("10:15:00"); // line 10
    diff = rpg_diff_hours(t1, t2); // line 13
    std::cout << rpg_to_char(diff) << std::endl;
    diff = rpg_diff_minutes(t1, t2); // line 17
    std::cout << rpg_to_char(diff) << std::endl;
    hr = rpg_subdt_hours(t1); // line 21
    std::cout << rpg_to_char(hr) << std::endl;
    mn = rpg_subdt_minutes(t1); // line 25
    std::cout << rpg_to_char(mn) << std::endl;
    t2 = (t1 + RpgDuration{2, 'H'}); // line 29
    std::cout << rpg_to_char(t2) << std::endl;
    return 0;
}
