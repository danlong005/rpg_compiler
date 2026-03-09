#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::array<int, 5> numbers;
    std::array<std::string, 3> names;
    int i = 0;
    int total = 0;
    int count = 0;
    numbers[1 - 1] = 10; // line 9
    numbers[2 - 1] = 20; // line 10
    numbers[3 - 1] = 30; // line 11
    numbers[4 - 1] = 40; // line 12
    numbers[5 - 1] = 50; // line 13
    total = 0; // line 16
    for (i = 1; i <= 5; i += 1) {
        total = (total + numbers[i - 1]); // line 18
    }
    std::cout << rpg_to_char(total) << std::endl;
    count = static_cast<int>(numbers.size()); // line 23
    std::cout << rpg_to_char(count) << std::endl;
    names[1 - 1] = "Alice"; // line 27
    names[2 - 1] = "Bob"; // line 28
    names[3 - 1] = "Charlie"; // line 29
    for (i = 1; i <= static_cast<int>(names.size()); i += 1) {
        std::cout << names[i - 1] << std::endl;
    }
    numbers[3 - 1] = 99; // line 36
    std::cout << rpg_to_char(numbers[3 - 1]) << std::endl;
    return 0;
}
