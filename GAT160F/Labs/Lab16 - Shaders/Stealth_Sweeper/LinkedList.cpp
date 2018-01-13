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





LinkedList::~LinkedList()
{
}
