#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int A = 0;
    int B = 0;
    int C = 0;
    int RESULT = 0;
    std::string S1;
    std::string S2;
    std::string SRESULT;
    A = 10; // line 11
    B = 25; // line 12
    RESULT = std::max(A, B); // line 13
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = std::min(A, B); // line 17
    std::cout << rpg_to_char(RESULT) << std::endl;
    C = 15; // line 21
    RESULT = std::max({A, B, C}); // line 22
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = std::min({A, B, C}); // line 26
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = std::max({3, 7, 1, 9, 4}); // line 30
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = std::min({3, 7, 1, 9, 4}); // line 32
    std::cout << rpg_to_char(RESULT) << std::endl;
    S1 = "Apple"; // line 36
    S2 = "Banana"; // line 37
    SRESULT = std::max(S1, S2); // line 38
    std::cout << SRESULT << std::endl;
    SRESULT = std::min(S1, S2); // line 40
    std::cout << SRESULT << std::endl;
    return 0;
}
