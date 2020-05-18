#pragma once

#include "Node.h"

#include "NonCopyable.h"
#include "Weight.h"

class Node;

class Edge : public NonCopyable
{
private:
	Node* from;
	Node* to;
	Weight weight;

public:
	Edge(Node* from, Node* to, Weight weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}

	Node* getFrom() const
	{
		return from;
	}

	Node* getTo() const
	{
		return to;
	}

	const Weight getWeight() const
	{
		return weight;
	}

	bool operator <(const Edge& other) {
		return weight < other.getWeight();
	}

	friend class Node;
};
