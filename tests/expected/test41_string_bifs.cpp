#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string STR;
    double NUM = 0.0;
    int FLT = 0;
    RpgDate MYDATE;
    STR = rpg_lower("HELLO WORLD"); // line 7
    std::cout << STR << std::endl;
    STR = rpg_upper("hello world"); // line 10
    std::cout << STR << std::endl;
    MYDATE = rpg_make_date("2024-06-15"); // line 15
    FLT = rpg_subdt_years(MYDATE); // line 16
    std::cout << rpg_to_char(FLT) << std::endl;
    FLT = rpg_subdt_months(MYDATE); // line 18
    std::cout << rpg_to_char(FLT) << std::endl;
    FLT = rpg_subdt_days(MYDATE); // line 20
    std::cout << rpg_to_char(FLT) << std::endl;
    NUM = 3.14; // line 24
    FLT = static_cast<int>((static_cast<double>(NUM) * 100)); // line 25
    std::cout << rpg_to_char(FLT) << std::endl;
    FLT = static_cast<int>(std::sqrt(static_cast<double>(144))); // line 29
    std::cout << rpg_to_char(FLT) << std::endl;
    return 0;
}
