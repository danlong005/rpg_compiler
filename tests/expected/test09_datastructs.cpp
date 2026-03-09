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
struct items_t {
    std::string desc;
    int qty = 0;
};
int main() {
    bool rpg_indicators[100] = {};
    employee_t employee;
    std::array<items_t, 3> items;
    int i = 0;
    int total = 0;
    employee.name = "Alice"; // line 9
    employee.age = 30; // line 10
    employee.salary = 75000.5; // line 11
    std::cout << employee.name << std::endl;
    std::cout << rpg_to_char(employee.age) << std::endl;
    std::cout << rpg_to_char(employee.salary) << std::endl;
    items[1 - 1].desc = "Widget"; // line 23
    items[1 - 1].qty = 10; // line 24
    items[2 - 1].desc = "Gadget"; // line 25
    items[2 - 1].qty = 20; // line 26
    items[3 - 1].desc = "Doohickey"; // line 27
    items[3 - 1].qty = 5; // line 28
    total = 0; // line 32
    for (i = 1; i <= 3; i += 1) {
        std::cout << items[i - 1].desc << std::endl;
        total = (total + items[i - 1].qty); // line 35
    }
    std::cout << rpg_to_char(total) << std::endl;
    return 0;
}
