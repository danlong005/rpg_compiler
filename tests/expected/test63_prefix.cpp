#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
struct CUSTREC_t {
    int CUST_ID = 0;
    std::string CUST_NAME;
    std::string CUST_CITY;
};
int main() {
    bool rpg_indicators[100] = {};
    CUSTREC_t CUSTREC;
    CUSTREC.CUST_ID = 100; // line 9
    CUSTREC.CUST_NAME = "John Smith"; // line 10
    CUSTREC.CUST_CITY = "New York"; // line 11
    std::cout << rpg_to_char(CUSTREC.CUST_ID) << std::endl;
    std::cout << rpg_trim(CUSTREC.CUST_NAME) << std::endl;
    std::cout << rpg_trim(CUSTREC.CUST_CITY) << std::endl;
    return 0;
}
