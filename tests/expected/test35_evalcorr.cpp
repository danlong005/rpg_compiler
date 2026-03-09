#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
struct SOURCE_t {
    std::string NAME;
    int AGE = 0;
    double SALARY = 0.0;
};
struct TARGET_t {
    std::string NAME;
    int AGE = 0;
    std::string DEPT;
};
int main() {
    bool rpg_indicators[100] = {};
    SOURCE_t SOURCE;
    TARGET_t TARGET;
    SOURCE.NAME = "Alice"; // line 14
    SOURCE.AGE = 30; // line 15
    SOURCE.SALARY = 75000.5; // line 16
    TARGET.DEPT = "IT"; // line 18
    TARGET.NAME = SOURCE.NAME;
    TARGET.AGE = SOURCE.AGE;
    std::cout << TARGET.NAME << std::endl;
    std::cout << rpg_to_char(TARGET.AGE) << std::endl;
    std::cout << TARGET.DEPT << std::endl;
    return 0;
}
