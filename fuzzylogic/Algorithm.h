#pragma once

#include <string>

class Algorithm
{
public:
  /*  enum class Complexity {
        constant,     // O(n)
        logarithmic,  // O(logn)
        linear,       // O(n)
        linearithmic, // O(nlogn)
        quadratic,    // O(n^2)
        cubic         // O(n^3)
    };*/
    virtual std::string getComplexity() const = 0;
    virtual std::string getName() const = 0;
};

