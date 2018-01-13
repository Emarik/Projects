#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"Node.h"

namespace csc195
{
	class LinkedList
	{
	public:
		LinkedList();
		void add(int data);
		void remove(int index);
		//void insert(int data, int index);
		int* toArray(int*,int) const;
		int size() const;
		~LinkedList();
	private:
		Node * list_head;
		int listsize;
	};
}
#endif
