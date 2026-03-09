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
int ADDNUMS(int P1, int P2);
int ADDNUMS(int P1, int P2) {
    return (P1 + P2);
}
int main() {
    bool rpg_indicators[100] = {};
    EMPLOYEE_t EMPLOYEE;
    int RESULT = 0;
    EMPLOYEE.NAME = "Alice"; // line 10
    EMPLOYEE.AGE = 30; // line 11
    EMPLOYEE.SALARY = 75000.5; // line 12
    std::cout << EMPLOYEE.NAME << std::endl;
    std::cout << rpg_to_char(EMPLOYEE.AGE) << std::endl;
    std::cout << rpg_to_char(EMPLOYEE.SALARY) << std::endl;
    RESULT = ADDNUMS(10, 20); // line 25
    std::cout << rpg_to_char(RESULT) << std::endl;
    return 0;
}
