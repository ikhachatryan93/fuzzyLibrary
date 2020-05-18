#pragma once
#include "Defuzzifier.h"

namespace fuzzy {

	class LastOfMaximum :
		public Defuzzifier
	{
        /**
         * @return Returns defuzzifier name
         */
        static std::string className() {
            return "LastOfMaximum";
        }

        /**
          Defuzzifies the given fuzzy number using the range
          @param fuzzy number
          @return the defuzzified value of the given fuzzy term
         */
        static double defuzzify(const FuzzyNumber*);
	};
}