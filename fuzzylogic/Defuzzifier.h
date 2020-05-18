#pragma once

#include <string>

#include "FuzzyNumber.h"

namespace fuzzy {

    class FuzzyNumber;

    class Defuzzifier {
    public:

        Defuzzifier() {
        }

        virtual ~Defuzzifier() {
        }

        /**
          @return Returns defuzzifier name
         */
        static std::string className()
        {
            return "Defuzzifier signature";
        }

        /**
          Defuzzifies the given fuzzy number using the range `[minimum,maximum]`

          @return the defuzzified value of the given fuzzy term
         */
        static double defuzzify(const FuzzyNumber*);
    };

}