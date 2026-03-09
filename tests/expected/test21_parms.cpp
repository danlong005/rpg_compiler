#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int myProc(int p1, int p2, int p3);
int myProc(int p1, int p2, int p3) {
    int numParms = 0;
    numParms = 3; // line 24
    std::cout << rpg_to_char(numParms) << std::endl;
    return ((p1 + p2) + p3);
}
int main() {
    bool rpg_indicators[100] = {};
    int result = 0;
    result = myProc(10, 20, 30); // line 11
    std::cout << rpg_to_char(result) << std::endl;
    return 0;
}
