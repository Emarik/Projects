#pragma once
#include "Renderable.h"
#include "Node.h"
struct LinkedList
{
public:
	LinkedList();
	void add(Renderable *r);
	~LinkedList();
	int used = 0;
	Node start;
};

