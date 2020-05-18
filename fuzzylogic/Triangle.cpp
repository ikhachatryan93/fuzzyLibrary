#include "Triangle.h"

namespace fuzzy{

double Triangle::getMembership(double t) const
{
    const auto left = getLeft(), right = getRight(), middle = getMiddle();
    if (t <= left) {
        return 0;
    }
    else if (t < middle) {
        return (t - left) / (middle - left);
    }
    else if (t == middle) {
        return 1.0;
    }
    else if (t < right) {
        return (right - t) / (right - middle);
    }
    else {
        return 0;
    }
}

void Triangle::add(const Triangle & op)
{
    const auto left = getLeft(), right = getRight(), middle = getMiddle();
    fuzzySet[0] = std::make_pair(left + op.getLeft(), 0);
    fuzzySet[1] = std::make_pair(middle + op.getMiddle(), 1);
    fuzzySet[2] = std::make_pair(right + op.getRight(), 0);
}

Triangle Triangle::operator+(const Triangle& op) const
{
    const auto left = getLeft(), right = getRight(), middle = getMiddle();
    std::vector<member> s(4);
    s[0] = std::make_pair(left + op.getLeft(), 0);
    s[1] = std::make_pair(middle + op.getMiddle(), 1);
    s[3] = std::make_pair(right + op.getRight(), 0);
    return Triangle(s);
}

Triangle& Triangle::operator+=(const Triangle& op)
{
    const auto left = getLeft(), right = getRight(), middle = getMiddle();
    fuzzySet[0] = std::make_pair(left + op.getLeft(), 0);
    fuzzySet[1] = std::make_pair(middle + op.getMiddle(), 1);
    fuzzySet[2] = std::make_pair(right + op.getRight(), 0);
    return *this;
}

}