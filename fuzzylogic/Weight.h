#pragma once

#include <limits>

#include "FuzzyNumber.h"

class Weight {
protected:
	fuzzy::FuzzyNumber* value;

public:
	fuzzy::FuzzyNumber* getValue() const {
		return value;
	}

	void setValue(fuzzy::FuzzyNumber* v)
	{
		value = v;
	}
};
