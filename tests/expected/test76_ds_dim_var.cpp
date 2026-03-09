#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
struct EMPLOYEE_t {
    std::string NAME;
    int AGE = 0;
};
int main() {
    bool rpg_indicators[100] = {};
    std::vector<EMPLOYEE_t> EMPLOYEE;
    EMPLOYEE.reserve(10);
    int I = 0;
    int COUNT = 0;
    EMPLOYEE.resize(3); // line 11
    EMPLOYEE[1 - 1].NAME = "Alice"; // line 13
    EMPLOYEE[1 - 1].AGE = 30; // line 14
    EMPLOYEE[2 - 1].NAME = "Bob"; // line 15
    EMPLOYEE[2 - 1].AGE = 25; // line 16
    EMPLOYEE[3 - 1].NAME = "Charlie"; // line 17
    EMPLOYEE[3 - 1].AGE = 35; // line 18
    COUNT = static_cast<int>(EMPLOYEE.size()); // line 20
    std::cout << rpg_to_char(COUNT) << std::endl;
    for (I = 1; I <= COUNT; I += 1) {
        std::cout << EMPLOYEE[I - 1].NAME << std::endl;
    }
    EMPLOYEE.resize(2); // line 29
    COUNT = static_cast<int>(EMPLOYEE.size()); // line 30
    std::cout << rpg_to_char(COUNT) << std::endl;
    return 0;
}
