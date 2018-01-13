#include "LinkedList.h"
#include <stdexcept>

using namespace std;
namespace csc195
{
LinkedList::LinkedList(void)
{
	list_head = 0;
	listsize = 0;
}

void LinkedList::add(int data)
{
	Node* current = new Node(data);
	if (this->list_head == 0)
	{
		this->list_head = current;
	}
	else
	{
		Node* walker = list_head;
		while (walker->next != 0)
		{												//(*walker).next = walker->next
			walker = walker->next;
		}
		walker->next = current;
	}
	this->listsize++;
}

void LinkedList::remove(int index)
{
	Node* removed = 0;
	Node* current = list_head;
	for (int I = 0; I < index-1; I++)
	{
		current = current->next;
	}
	if (index == 0)
	{
		removed = list_head;
		list_head = list_head->next;
	}
	else
	{
		removed = current->next;
		current->next = current->next->next;
	}
	removed->next = 0;
	delete removed;
	listsize--;
}

int* LinkedList::toArray(int* dst,int size)const
{
	//int* arr = new int[size()];
	if (size < this->size())
	{
		throw exception("Your buffer is too small");
	}
	Node* current = list_head;
	int i = 0;
	while (current != 0)
	{
		dst[i] = current->getData();
		current = current->next;
		i++;
	}
	return dst;
}

int LinkedList::size() const
{
	return listsize;
}

LinkedList::~LinkedList()
{
	/*for (int I = size(); I > 0; I--)
	{
		remove(I);
	}*/
	if (list_head != 0)
	{
		delete list_head;
		list_head = 0;
	}
}
}