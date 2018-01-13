#pragma once
#include "Renderable.h"
#include "Node.h"
struct LinkedList
{
public:
	LinkedList();
	void add(Renderable *r);
	Renderable * getRenderable(std::string);
	~LinkedList();
	int used = 0;
	Node start;
};

