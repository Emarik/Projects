#include "Node.h"
#include <iostream>

using namespace std;
namespace csc195
{
	Node::Node(int data,Node* next)
	{
		this->data = data;
		this->next = next;
	}
	int Node::getData() const
	{
		return this->data;
	}
	void Node::setData(int data)
	{
		if (data < 0)
		{
			throw exception("something");
		}
		this->data = data;
	}

	Node::~Node()
	{
		if (next != 0)
		{
			delete next;
			next = 0;
		}
	}
}