#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
static const std::string RPG_DATFMT = "*USA";
static const std::string RPG_TIMFMT = "*USA";
int main() {
    bool rpg_indicators[100] = {};
    RpgDate myDate;
    RpgTime myTime;
    std::string dateStr;
    std::string timeStr;
    myDate = rpg_make_date("2024-03-15"); // line 9
    dateStr = rpg_to_char(myDate, RPG_DATFMT); // line 12
    std::cout << dateStr << std::endl;
    std::cout << rpg_to_char(myDate, RPG_DATFMT) << std::endl;
    myTime = rpg_make_time("14:30:00"); // line 18
    std::cout << rpg_to_char(myTime, RPG_TIMFMT) << std::endl;
    return 0;
}
