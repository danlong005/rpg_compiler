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
    RpgDate MYDATE2;
    RpgTime MYTIME;
    RpgTimestamp MYTIMESTAMP;
    std::string RESULT;
    int DAYS = 0;
    MYDATE = rpg_make_date("2024-03-15"); // line 10
    RESULT = rpg_to_char(MYDATE); // line 11
    std::cout << RESULT << std::endl;
    MYTIME = rpg_make_time("14:30:00"); // line 15
    RESULT = rpg_to_char(MYTIME); // line 16
    std::cout << RESULT << std::endl;
    MYTIMESTAMP = rpg_make_timestamp("2024-03-15-14.30.00.000000"); // line 20
    RESULT = rpg_to_char(MYTIMESTAMP); // line 21
    std::cout << RESULT << std::endl;
    MYDATE2 = rpg_make_date("2024-03-20"); // line 25
    DAYS = rpg_diff_days(MYDATE2, MYDATE); // line 26
    std::cout << rpg_to_char(DAYS) << std::endl;
    MYDATE2 = (MYDATE + RpgDuration{10, 'D'}); // line 30
    RESULT = rpg_to_char(MYDATE2); // line 31
    std::cout << RESULT << std::endl;
    MYDATE2 = (MYDATE + RpgDuration{2, 'M'}); // line 34
    RESULT = rpg_to_char(MYDATE2); // line 35
    std::cout << RESULT << std::endl;
    MYDATE2 = (MYDATE + RpgDuration{1, 'Y'}); // line 38
    RESULT = rpg_to_char(MYDATE2); // line 39
    std::cout << RESULT << std::endl;
    return 0;
}
