#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
struct source_t {
    std::string name;
    int age = 0;
    double salary = 0.0;
};
struct target_t {
    std::string name;
    int age = 0;
    std::string dept;
};
int main() {
    bool rpg_indicators[100] = {};
    source_t source;
    target_t target;
    source.name = "Alice"; // line 14
    source.age = 30; // line 15
    source.salary = 75000.5; // line 16
    target.dept = "IT"; // line 18
    target.name = source.name;
    target.age = source.age;
    std::cout << target.name << std::endl;
    std::cout << rpg_to_char(target.age) << std::endl;
    std::cout << target.dept << std::endl;
    return 0;
}
