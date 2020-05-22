#pragma once

#include "Algorithm.h"

#include "Triangle.h"

#include <string>
#include <vector>

class Prim : public Algorithm
{
public:
    virtual std::string getComplexity() const
    {
        return "O(n^2)";
    }
    
    virtual std::string getName() const
    {
        return "Prim";
    }

    // static std::vector<unsigned> getMst(std::vector<std::vector<fuzzy::Triangle>>&);
    static std::vector<unsigned> getMstScalar(std::vector<std::vector<fuzzy::Triangle>>&);
    static std::vector<unsigned> getMstFuzzy(std::vector<std::vector<fuzzy::Triangle>>&);
    static std::vector<unsigned> getMst(std::vector<std::vector<double>>&);
    static std::vector<unsigned> getMst(std::vector<std::vector<int>>&);
};
