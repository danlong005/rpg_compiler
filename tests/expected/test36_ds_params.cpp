#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
struct RESULT_t {
    int SUM = 0;
    int PRODUCT = 0;
};
void CALCBOTH(int A, int B, RESULT_t& RES);
void CALCBOTH(int A, int B, RESULT_t& RES) {
    RES.SUM = (A + B); // line 19
    RES.PRODUCT = (A * B); // line 20
}
int main() {
    bool rpg_indicators[100] = {};
    RESULT_t RESULT;
    CALCBOTH(5, 7, RESULT);
    std::cout << rpg_to_char(RESULT.SUM) << std::endl;
    std::cout << rpg_to_char(RESULT.PRODUCT) << std::endl;
    return 0;
}
