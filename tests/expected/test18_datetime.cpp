#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    RpgDate myDate;
    RpgDate myDate2;
    RpgTime myTime;
    RpgTimestamp myTimestamp;
    std::string result;
    int days = 0;
    myDate = rpg_make_date("2024-03-15"); // line 10
    result = rpg_to_char(myDate); // line 11
    std::cout << result << std::endl;
    myTime = rpg_make_time("14:30:00"); // line 15
    result = rpg_to_char(myTime); // line 16
    std::cout << result << std::endl;
    myTimestamp = rpg_make_timestamp("2024-03-15-14.30.00.000000"); // line 20
    result = rpg_to_char(myTimestamp); // line 21
    std::cout << result << std::endl;
    myDate2 = rpg_make_date("2024-03-20"); // line 25
    days = rpg_diff_days(myDate2, myDate); // line 26
    std::cout << rpg_to_char(days) << std::endl;
    myDate2 = (myDate + RpgDuration{10, 'D'}); // line 30
    result = rpg_to_char(myDate2); // line 31
    std::cout << result << std::endl;
    myDate2 = (myDate + RpgDuration{2, 'M'}); // line 34
    result = rpg_to_char(myDate2); // line 35
    std::cout << result << std::endl;
    myDate2 = (myDate + RpgDuration{1, 'Y'}); // line 38
    result = rpg_to_char(myDate2); // line 39
    std::cout << result << std::endl;
    return 0;
}
