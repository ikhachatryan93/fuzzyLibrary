#pragma once
#include <iostream>
#include <string>

#include "FuzzySet.h"

namespace fuzzy {

	class FuzzyNumber : public FuzzySet
	{
	protected:
		char type;
		std::string name;

	public:
		FuzzyNumber() = delete;
		FuzzyNumber(const std::vector<member>& s, char t) : FuzzySet(s), type(t) { /*TODO throw exception if is not convex and normal set */}

		// set and get functions
	public:
		void setLeft(double l)
		{
			fuzzySet[0] = std::make_pair(l, 0);
		}

		double getLeft() const
		{
			return fuzzySet[0].first;
		}

		void setRight(double r)
		{
			fuzzySet[fuzzySet.size() - 1] = std::make_pair(r, 0);
		}

		double getRight() const
		{
			return fuzzySet[fuzzySet.size() - 1].first;
		}

		virtual void setType(char c)
		{
			type = c;
		}

		char getType(void) const {
			return type;
		}

		virtual void setName(const std::string& s)
		{
			name = s;
		}

		void getName() const
		{
			std::cout << name << std::endl;
		}

		virtual double getMembership(double t) const = 0 ;
	};

}