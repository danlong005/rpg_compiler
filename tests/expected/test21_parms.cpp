#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int MYPROC(int P1, int P2, int P3);
int MYPROC(int P1, int P2, int P3) {
    int NUMPARMS = 0;
    NUMPARMS = 3; // line 24
    std::cout << rpg_to_char(NUMPARMS) << std::endl;
    return ((P1 + P2) + P3);
}
int main() {
    bool rpg_indicators[100] = {};
    int RESULT = 0;
    RESULT = MYPROC(10, 20, 30); // line 11
    std::cout << rpg_to_char(RESULT) << std::endl;
    return 0;
}
