#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

#include "Weight.h"
#include "Prim.h"
#include "NonCopyable.h"
#include "Triangle.h"
#include "Trapezoid.h"


// Implemantation of template Graph represented in adjacency list
template<class WeightT>
class Graph: public NonCopyable
{
	std::vector<std::vector<WeightT>> adjMatrix;
	std::vector<unsigned> mst;

public:
	Graph() = default;
	Graph(std::vector<std::vector<WeightT>> m)
	{
		adjMatrix = std::move(m);
	}

	unsigned getSize() const
	{
		return adjMatrix.size();
	}

	std::vector<std::vector<WeightT>>& getAdjMatrix()
	{
		return adjMatrix;
	}

	template <class Algorithm>
	void calculateMst(Algorithm calculateMst) {
		this->mst = calculateMst(adjMatrix);
	}

	void randomFill(unsigned s);

	void print() {
		std::cout << "GRAPH\n----------------------------------\n";
		for (unsigned i = 0; i < adjMatrix.size(); ++i) {
			for (unsigned j = 0; j < adjMatrix.size(); ++j) {
				std::cout << adjMatrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << "----------------------------------------- \n\n";

	}
	
	void PrintMst() {
		std::cout << "\nMST\n---------------------------------\n";
		for (unsigned i = 1; i < adjMatrix.size(); i++) {
			std::cout << mst[i] << " - " << i << " \t" << adjMatrix[i][mst[i]] << " \n";
		}
		std::cout << "-------------------------------------- \n\n";

	}
};
