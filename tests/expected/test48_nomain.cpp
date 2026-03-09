#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int sharedVal = 42;
const auto _init_sharedVal = sharedVal;
int add(int a, int b) {
    return (a + b);
}
