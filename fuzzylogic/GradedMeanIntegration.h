#pragma once
#include "Defuzzifier.h"
#include "FuzzyNumber.h"

#include <string>

namespace fuzzy {

    class GradedMeanIntegration : public Defuzzifier {
    public:

        /**
         * @return Returns defuzzifier name
         */
        static std::string className() {
            return "GradedMeanIntegration";
        }

        /**
          Defuzzifies the given fuzzy number using the range
          @param fuzzy number
          @return the defuzzified value of the given fuzzy term
         */
        static double defuzzify(const FuzzyNumber*);
    };

}