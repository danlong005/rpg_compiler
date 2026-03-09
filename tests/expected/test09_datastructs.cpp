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
    double SALARY = 0.0;
};
struct ITEMS_t {
    std::string DESC;
    int QTY = 0;
};
int main() {
    bool rpg_indicators[100] = {};
    EMPLOYEE_t EMPLOYEE;
    std::array<ITEMS_t, 3> ITEMS;
    int I = 0;
    int TOTAL = 0;
    EMPLOYEE.NAME = "Alice"; // line 9
    EMPLOYEE.AGE = 30; // line 10
    EMPLOYEE.SALARY = 75000.5; // line 11
    std::cout << EMPLOYEE.NAME << std::endl;
    std::cout << rpg_to_char(EMPLOYEE.AGE) << std::endl;
    std::cout << rpg_to_char(EMPLOYEE.SALARY) << std::endl;
    ITEMS[1 - 1].DESC = "Widget"; // line 23
    ITEMS[1 - 1].QTY = 10; // line 24
    ITEMS[2 - 1].DESC = "Gadget"; // line 25
    ITEMS[2 - 1].QTY = 20; // line 26
    ITEMS[3 - 1].DESC = "Doohickey"; // line 27
    ITEMS[3 - 1].QTY = 5; // line 28
    TOTAL = 0; // line 32
    for (I = 1; I <= 3; I += 1) {
        std::cout << ITEMS[I - 1].DESC << std::endl;
        TOTAL = (TOTAL + ITEMS[I - 1].QTY); // line 35
    }
    std::cout << rpg_to_char(TOTAL) << std::endl;
    return 0;
}
