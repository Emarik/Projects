#include "LinkedList.h"



LinkedList::LinkedList()
{

}

void LinkedList::add(Renderable* r)
{
	{
		Node*p = &start;
		while (p->next != NULL)
		{
			
			p = p->next;
		}
		p->next = new Node();
		p->next->r = r;
		p->next->next = NULL;
		used++;
	}
}

Renderable* LinkedList::getRenderable(std::string name)
{
	Node*p = &start;
	while (p->next != NULL)
	{
		if (p->next->r->name == name)
		{
			return p->next->r;
		}
		p = p->next;
	}
	return nullptr;
}





LinkedList::~LinkedList()
{
}
