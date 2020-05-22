#pragma once

#include "FuzzyNumber.h"

#include <vector>

namespace fuzzy {
	
	class Triangle : public FuzzyNumber
	{
	public:
		Triangle(double l, double m, double r)
			: FuzzyNumber(std::vector<std::pair<double, double>>({ std::make_pair(l,0), std::make_pair(m,1), std::make_pair(r,0)}), 't')
		{
		}

		Triangle(const std::vector<FuzzySet::member>& n)
			: FuzzyNumber(n, 't')
		{
			if (n.size() != 3) {
				throw "Non triangle fuzzy number is provided";
			}
		}

		Triangle()
			: FuzzyNumber(std::vector<std::pair<double, double>>({ std::make_pair(0,0), std::make_pair(0,1), std::make_pair(0,0) }), 't')
		{
		}

	public:


		void setMiddle(double dL, double = 0)
		{
			fuzzySet[1] = std::make_pair(dL, 1);
		}

		double getMiddle() const
		{
			return fuzzySet[1].first;
		}

		double getMembership(double t) const;
		Triangle operator+(const Triangle&) const;
		Triangle& operator+=(const Triangle&);
		bool operator==(const Triangle&) const ;
		bool operator!=(const Triangle& op) const;

	};
}

