#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
struct ADDRESS_t {
    std::string FULLADDR;
    std::string CITY; // OVERLAY(FULLADDR)
    std::string STATE; // OVERLAY(FULLADDR:21)
    std::string ZIP; // OVERLAY(FULLADDR:23)
};
struct RECORD_t {
    int ID = 0; // POS(1)
    std::string NAME; // POS(5)
};
int main() {
    bool rpg_indicators[100] = {};
    ADDRESS_t ADDRESS;
    RECORD_t RECORD;
    ADDRESS.CITY = "Minneapolis"; // line 16
    ADDRESS.STATE = "MN"; // line 17
    ADDRESS.ZIP = "55401"; // line 18
    std::cout << rpg_trim(ADDRESS.CITY) << std::endl;
    std::cout << ADDRESS.STATE << std::endl;
    std::cout << rpg_trim(ADDRESS.ZIP) << std::endl;
    RECORD.ID = 1; // line 24
    RECORD.NAME = "Test Record"; // line 25
    std::cout << rpg_to_char(RECORD.ID) << std::endl;
    std::cout << rpg_trim(RECORD.NAME) << std::endl;
    return 0;
}
