#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int ADD(int A, int B);
int FACTORIAL(int N);
std::string GREET(std::string NAME);
int ADD(int A, int B) {
    return (A + B);
}
int FACTORIAL(int N) {
    if (N <= 1) {
        return 1;
    }
    return (N * FACTORIAL((N - 1)));
}
std::string GREET(std::string NAME) {
    std::string RESULT;
    RESULT = (("Hello, " + NAME) + "!"); // line 55
    return RESULT;
}
int main() {
    bool rpg_indicators[100] = {};
    int RESULT = 0;
    std::string MSG;
    RESULT = ADD(10, 20); // line 20
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = FACTORIAL(5); // line 23
    std::cout << rpg_to_char(RESULT) << std::endl;
    MSG = GREET("RPG"); // line 26
    std::cout << MSG << std::endl;
    return 0;
}
