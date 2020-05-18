#pragma once

#include <set>
#include <utility>
#include <vector>
#include <iostream>

namespace fuzzy {

	class FuzzySet
	{
	protected: 
		typedef std::pair<double, double> member;

	protected:
		std::vector<member> fuzzySet;
	
	public:
		FuzzySet(std::vector<member> s) : fuzzySet(s) {};

		const std::vector<member>& getSet() const
		{
			return fuzzySet;
		}

		// Two fuzzy sets A(x) and B(x) are said to be unequal, if µA(x) ≠ µB(x) for at least x ∈ X
		bool operator==(const FuzzySet& other) const
		{
			if (fuzzySet.size() != other.fuzzySet.size()) {
				return false;
			}

			for (auto i = fuzzySet.size() - 1; i != 0; --i) {
				if (fuzzySet[i].first != other.fuzzySet[i].first) {
					return false;
				}
			}
			return true;
		}

		FuzzySet operator+(const FuzzySet&) const;
		FuzzySet operator*(const FuzzySet&) const;
		FuzzySet unionMaximin(const FuzzySet&) const;
		FuzzySet intersectMaximin(const FuzzySet&) const;
		FuzzySet complement() const;

		friend std::ostream& operator<<(std::ostream& os, const FuzzySet& t);
	};

	std::ostream& operator<<(std::ostream& os, const FuzzySet& t);
}
