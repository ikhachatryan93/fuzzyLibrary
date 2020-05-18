#include "GradedMeanIntegration.h"

#include "Triangle.h"
#include "Trapezoid.h"

#include <stdexcept>

namespace fuzzy {
 
    double fuzzy::GradedMeanIntegration::defuzzify(const fuzzy::FuzzyNumber* numberPtr)
    {
        // handle triangle fuzzy number
        if (numberPtr->getType() == 't') {
            return 1.0 / 6 * (numberPtr->getLeft() + 4 * (dynamic_cast<const Triangle*>(numberPtr))->getMiddle() + numberPtr->getRight());
        }
        else if (numberPtr->getType() == 'z') {
            return 1.0 / 6 * (
                numberPtr->getLeft() +
                4 * (dynamic_cast<const Trapezoid*>(numberPtr))->getLeftMiddle() +
                4 * (dynamic_cast<const Trapezoid*>(numberPtr))->getRightMiddle() + numberPtr->getRight()
                );

        }
        else {
            throw std::runtime_error("Invalid number type");
        }
    }    
}