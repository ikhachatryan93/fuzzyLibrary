#include "FuzzySet.h"

#include <forward_list>
#include "FuzzySet.h"

#include <utility>
#include <algorithm>
#include <vector>

namespace fuzzy {

	// Maximin
	FuzzySet FuzzySet::unionMaximin(const FuzzySet& other) const
	{
		
		auto first1 = this->fuzzySet.cbegin();
		auto last1 = this->fuzzySet.cend();

		auto first2 = other.fuzzySet.cbegin();
		auto last2 = other.fuzzySet.cend();

		std::vector<member> result;
		result.reserve(other.fuzzySet.size() + this->fuzzySet.size());

		while (true) {
			if (first1 == last1) { result.insert(result.end(), first2, last2); break; }
			if (first2 == last2) { result.insert(result.end(), first1, last1); break; }


			if ((*first1).first == (*first2).first) {
				result.push_back(std::max(*first1++, *first2++));
			} else {
				if ((*first1).first < (*first2).first) {
					result.push_back(*first1++);
				} else {
					result.push_back(*first2++);
				}
			}
		}

		return FuzzySet(result);
	}

	// Maximin
	FuzzySet FuzzySet::intersectMaximin(const FuzzySet& other) const
	{
		auto first1 = this->fuzzySet.cbegin();
		auto last1 = this->fuzzySet.cend();

		auto first2 = other.fuzzySet.cbegin();
		auto last2 = other.fuzzySet.cend();

		std::vector<member> result;
		result.reserve(other.fuzzySet.size() + this->fuzzySet.size());

		while (true) {
			if (first1 == last1) { result.insert(result.end(), first2, last2); break; }
			if (first2 == last2) { result.insert(result.end(), first1, last1); break; }


			if ((*first1).first == (*first2).first) {
				result.push_back(std::min(*first1++, *first2++));
			}
			else {
				if ((*first1).first < (*first2).first) {
					result.push_back(*first1++);
				}
				else {
					result.push_back(*first2++);
				}
			}
		}

		return FuzzySet(result);
	}

	FuzzySet FuzzySet::complement() const
	{
		std::vector<member> result;
		result.reserve(this->fuzzySet.size());

		for (auto i = this->fuzzySet.cbegin(); i != this->fuzzySet.cend(); ++i) {
			result.push_back(std::make_pair((*i).first, 1-(*i).second));
		}

		return FuzzySet(result);
	}


	// A + B = N(A) + N(B) - N(A) * N(B)
	FuzzySet FuzzySet::operator+(const FuzzySet& other) const
	{
		auto first1 = this->fuzzySet.cbegin();
		auto last1 = this->fuzzySet.cend();

		auto first2 = other.fuzzySet.cbegin();
		auto last2 = other.fuzzySet.cend();

		std::vector<member> result;
		result.reserve(other.fuzzySet.size() + this->fuzzySet.size());

		while (true) {
			if (first1 == last1) { result.insert(result.end(), first2, last2); break; }
			if (first2 == last2) { result.insert(result.end(), first1, last1); break; }


			if ((*first1).first == (*first2).first) {
				result.push_back(std::make_pair((*first1).first, 1 - (1 - (*first1).second) * (1 - (*first2).second)));
				++first1; ++first2;
			} else {
				if ((*first1).first < (*first2).first) {
					result.push_back(*first1);
					++first1;
				} else {
					result.push_back(*first2);
					++first2;
				}
			}
		}

		return FuzzySet(result);
	}


	// A*B = N(A) * N(B)
	FuzzySet FuzzySet::operator*(const FuzzySet& other) const
	{
		auto first1 = this->fuzzySet.cbegin();
		auto last1 = this->fuzzySet.cend();

		auto first2 = other.fuzzySet.cbegin();
		auto last2 = other.fuzzySet.cend();

		std::vector<member> result;
		result.reserve(other.fuzzySet.size() + this->fuzzySet.size());

		while (true) {
			if (first1 == last1) { result.insert(result.end(), first2, last2); break; }
			if (first2 == last2) { result.insert(result.end(), first1, last1); break; }

			if ((*first1).first == (*first2).first) {
				result.push_back(std::make_pair((*first1).first, (*first1).second * (*first2).second));
				++first1; ++first2;
			} else {
				if ((*first1).first < (*first2).first) {
					++first1;
				}
				else {
					++first2;
				}
			}
		}

		return FuzzySet(result);
	}


	std::ostream& operator<<(std::ostream& os, const FuzzySet& t)
	{
		os << '(';
		for (const auto& i : t.getSet()) {
			os << '(' << i.first << ',' << i.second << ')';
		}
		os << ')';
		return os;
	}

} // namespace fuzzy