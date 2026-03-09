#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
static const std::string RPG_DATFMT = "*JUL";
int main() {
    bool rpg_indicators[100] = {};
    RpgDate MYDATE;
    std::string RESULT;
    MYDATE = rpg_make_date("2024-03-15"); // line 7
    RESULT = rpg_to_char(MYDATE, RPG_DATFMT); // line 11
    std::cout << RESULT << std::endl;
    return 0;
}
