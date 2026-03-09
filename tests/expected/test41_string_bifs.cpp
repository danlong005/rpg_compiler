#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string str;
    double num = 0.0;
    int flt = 0;
    RpgDate myDate;
    str = rpg_lower("HELLO WORLD"); // line 7
    std::cout << str << std::endl;
    str = rpg_upper("hello world"); // line 10
    std::cout << str << std::endl;
    myDate = rpg_make_date("2024-06-15"); // line 15
    flt = rpg_subdt_years(myDate); // line 16
    std::cout << rpg_to_char(flt) << std::endl;
    flt = rpg_subdt_months(myDate); // line 18
    std::cout << rpg_to_char(flt) << std::endl;
    flt = rpg_subdt_days(myDate); // line 20
    std::cout << rpg_to_char(flt) << std::endl;
    num = 3.14; // line 24
    flt = static_cast<int>((static_cast<double>(num) * 100)); // line 25
    std::cout << rpg_to_char(flt) << std::endl;
    flt = static_cast<int>(std::sqrt(static_cast<double>(144))); // line 29
    std::cout << rpg_to_char(flt) << std::endl;
    return 0;
}
