#include "Trapezoid.h"

namespace fuzzy {

double Trapezoid::getMembership(double t) const
{
    const auto left = getLeft(), right = getRight(), leftMiddle = getLeftMiddle(), rightMiddle = getRightMiddle();
    if (t <= left) {
        return 0;
    }
    else if (t < leftMiddle) {
        return (t - left) / (leftMiddle - left);
    }
    else if (t <= rightMiddle) {
        return 1.0;
    }
    else if (t < right) {
        return (right - t) / (right - rightMiddle);
    }
    else {
        return 0;
    }
}

Trapezoid Trapezoid::operator+(const Trapezoid& op) const
{
    const auto left = getLeft(), right = getRight(), leftMiddle = getLeftMiddle(), rightMiddle = getRightMiddle();

    std::vector<member> s(4);
    s[0] = std::make_pair(left + op.getLeft(), 0);
    s[1] = std::make_pair(leftMiddle + op.getLeftMiddle(), 1);
    s[2] = std::make_pair(rightMiddle + op.getRightMiddle(), 1);
    s[3] = std::make_pair(right + op.getRight(), 0);
    return Trapezoid(s);
}

Trapezoid& Trapezoid::operator+=(const Trapezoid& op)
{
    const auto left = getLeft(), right = getRight(), leftMiddle = getLeftMiddle(), rightMiddle = getRightMiddle();

    fuzzySet[0] = std::make_pair(left + op.getLeft(), 0);
    fuzzySet[1] = std::make_pair(leftMiddle + op.getLeftMiddle(), 1);
    fuzzySet[2] = std::make_pair(rightMiddle + op.getRightMiddle(), 1);
    fuzzySet[3] = std::make_pair(right + op.getRight(), 0);
    return *this;
}

}