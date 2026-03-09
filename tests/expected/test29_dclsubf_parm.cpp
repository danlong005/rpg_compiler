#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
struct employee_t {
    std::string name;
    int age = 0;
    double salary = 0.0;
};
int addNums(int p1, int p2);
int addNums(int p1, int p2) {
    return (p1 + p2);
}
int main() {
    bool rpg_indicators[100] = {};
    employee_t employee;
    int result = 0;
    employee.name = "Alice"; // line 10
    employee.age = 30; // line 11
    employee.salary = 75000.5; // line 12
    std::cout << employee.name << std::endl;
    std::cout << rpg_to_char(employee.age) << std::endl;
    std::cout << rpg_to_char(employee.salary) << std::endl;
    result = addNums(10, 20); // line 25
    std::cout << rpg_to_char(result) << std::endl;
    return 0;
}
