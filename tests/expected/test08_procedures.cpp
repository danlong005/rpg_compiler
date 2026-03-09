#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int add(int a, int b);
int factorial(int n);
std::string greet(std::string name);
int add(int a, int b) {
    return (a + b);
}
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return (n * factorial((n - 1)));
}
std::string greet(std::string name) {
    std::string result;
    result = (("Hello, " + name) + "!"); // line 55
    return result;
}
int main() {
    bool rpg_indicators[100] = {};
    int result = 0;
    std::string msg;
    result = add(10, 20); // line 20
    std::cout << rpg_to_char(result) << std::endl;
    result = factorial(5); // line 23
    std::cout << rpg_to_char(result) << std::endl;
    msg = greet("RPG"); // line 26
    std::cout << msg << std::endl;
    return 0;
}
