#pragma once

#include "FuzzyNumber.h"


namespace fuzzy {

	class Trapezoid : public FuzzyNumber
	{
	public:
		Trapezoid(double l, double r, double ml, double mr)
			: FuzzyNumber(std::vector<std::pair<double, double>>({ std::make_pair(l,0), std::make_pair(ml,1), std::make_pair(mr,1), std::make_pair(r,0) }), 'z')
		{
		}

		Trapezoid(const std::vector<FuzzySet::member>& n)
			: FuzzyNumber(n, 'z')
		{
			if (n.size() != 4) {
				throw "Non trapezoid fuzzy number is provided";
			}
		}

		Trapezoid ()
			: FuzzyNumber(std::move(std::vector<std::pair<double, double>>({ std::make_pair(0,0), std::make_pair(0,1), std::make_pair(0,1), std::make_pair(0,0)})), 'z')
		{
		}

		void setLeftMiddle(double dL)
		{
			fuzzySet[1] = std::make_pair(dL, 1);
		}

		void setRightMiddle(double dR)
		{
			fuzzySet[2] = std::make_pair(dR, 1);
		}

		double getLeftMiddle() const
		{
			return fuzzySet[1].first;
		}

		double getRightMiddle() const
		{
			return fuzzySet[2].first;
		}

		double getMembership(double t) const;
		bool operator==(const Trapezoid& op) const;
		bool operator!=(const Trapezoid& op) const;
		Trapezoid operator+(const Trapezoid&) const;
		Trapezoid& operator+=(const Trapezoid&);

	};
}
