#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
static const std::string RPG_DATFMT = "*USA";
static const std::string RPG_TIMFMT = "*USA";
int main() {
    bool rpg_indicators[100] = {};
    RpgDate MYDATE;
    RpgTime MYTIME;
    std::string DATESTR;
    std::string TIMESTR;
    MYDATE = rpg_make_date("2024-03-15"); // line 9
    DATESTR = rpg_to_char(MYDATE, RPG_DATFMT); // line 12
    std::cout << DATESTR << std::endl;
    std::cout << rpg_to_char(MYDATE, RPG_DATFMT) << std::endl;
    MYTIME = rpg_make_time("14:30:00"); // line 18
    std::cout << rpg_to_char(MYTIME, RPG_TIMFMT) << std::endl;
    return 0;
}
