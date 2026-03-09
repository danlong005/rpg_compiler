#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int SHAREDVAL = 42;
const auto _init_SHAREDVAL = SHAREDVAL;
int ADD(int A, int B) {
    return (A + B);
}
