#pragma once

#include <iostream>

#include "Triangle.h"

namespace Random
{

    int integer(int from = 0, int to = USHRT_MAX);
    double dbl(double from, double to);
    fuzzy::Triangle triangle();
}
