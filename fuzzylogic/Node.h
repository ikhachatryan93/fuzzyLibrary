# pragma once

#include "Edge.h"

#include <forward_list>
#include <string>

class Edge;

class Node
{
private:
	bool visited = false;
	std::forward_list<Edge*> edges;

public:
	const std::forward_list<Edge*> getEdges() const
	{
		return edges;
	}
	friend class Edge;
};

