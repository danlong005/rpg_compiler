#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
struct result_t {
    int sum = 0;
    int product = 0;
};
void calcBoth(int a, int b, result_t& res);
void calcBoth(int a, int b, result_t& res) {
    res.sum = (a + b); // line 19
    res.product = (a * b); // line 20
}
int main() {
    bool rpg_indicators[100] = {};
    result_t result;
    calcBoth(5, 7, result);
    std::cout << rpg_to_char(result.sum) << std::endl;
    std::cout << rpg_to_char(result.product) << std::endl;
    return 0;
}
