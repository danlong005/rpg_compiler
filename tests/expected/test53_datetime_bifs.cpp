#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    RpgTime T1;
    RpgTime T2;
    int DIFF = 0;
    int HR = 0;
    int MN = 0;
    T1 = rpg_make_time("14:30:00"); // line 9
    T2 = rpg_make_time("10:15:00"); // line 10
    DIFF = rpg_diff_hours(T1, T2); // line 13
    std::cout << rpg_to_char(DIFF) << std::endl;
    DIFF = rpg_diff_minutes(T1, T2); // line 17
    std::cout << rpg_to_char(DIFF) << std::endl;
    HR = rpg_subdt_hours(T1); // line 21
    std::cout << rpg_to_char(HR) << std::endl;
    MN = rpg_subdt_minutes(T1); // line 25
    std::cout << rpg_to_char(MN) << std::endl;
    T2 = (T1 + RpgDuration{2, 'H'}); // line 29
    std::cout << rpg_to_char(T2) << std::endl;
    return 0;
}
