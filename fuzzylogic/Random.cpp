#include "Random.h"
#include "Triangle.h"

#include <cstdlib>
#include <vector>
#include <array>

namespace Random {
    int integer(int f, int l)
    {
        return (rand() % (l-f)) + f;
    }

    double dbl(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    fuzzy::Triangle triangle() {
        return std::move(fuzzy::Triangle(integer(0, 10), integer(11, 20), integer(21, 30)));
    }

    // implement fuzzySet generator
    // fuzzy::FuzzySet fuzzySet(unsigned s) {
    //     
    // }
}