#pragma once
#include "Defuzzifier.h"

namespace fuzzy {

	class MiddleOfMaximum :
		public Defuzzifier
	{
        /**
         * @return Returns defuzzifier name
         */
        static std::string className() {
            return "MiddleOfMaximum";
        }

        /**
          Defuzzifies the given fuzzy number using the range
          @param fuzzy number
          @return the defuzzified value of the given fuzzy term
         */
        static double defuzzify(const FuzzyNumber*);
	};

}