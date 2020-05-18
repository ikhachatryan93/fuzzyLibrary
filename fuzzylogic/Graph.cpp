#include "Graph.h"

#include "Triangle.h"
#include "Random.h"

void Graph<fuzzy::Triangle>::randomFill(unsigned s)
{
	adjMatrix.resize(s);
	std::for_each(adjMatrix.begin(), adjMatrix.end(), [s](std::vector<fuzzy::Triangle>& adj) { adj.resize(s); });

	for (unsigned i = 0; i < s; ++i) {
		for (unsigned j = i; j < s; ++j) {
			if (i == j) {
				adjMatrix[i][j] = fuzzy::Triangle();
			}
			else {
				auto w = std::move(Random::triangle());
				adjMatrix[i][j] = w;
				adjMatrix[j][i] = w;
			}
		}
	}
}

void Graph<int>::randomFill(unsigned s) {
	adjMatrix.resize(s);
	std::for_each(adjMatrix.begin(), adjMatrix.end(), [s](std::vector<int>& adj) { adj.resize(s); });
	for (unsigned i = 0; i < s; ++i) {
		for (unsigned j = i; j < s; ++j) {
			if (i == j) {
				adjMatrix[i][j] = 0;
			}
			else {
				auto w = Random::integer() % 10;
				adjMatrix[i][j] = w;
				adjMatrix[j][i] = w;
			}
		}
	}
}

void Graph<double>::randomFill(unsigned s) {
	adjMatrix.resize(s);
	std::for_each(adjMatrix.begin(), adjMatrix.end(), [s](std::vector<double>& adj) { adj.resize(s); });

	for (unsigned i = 0; i < s; ++i) {
		for (unsigned j = i; j < s; ++j) {
			if (i == j) {
				adjMatrix[i][j] = 0;
			}
			else {
				auto w = Random::dbl(0, 10);
				adjMatrix[i][j] = w;
				adjMatrix[j][i] = w;
			}
		}
	}
}