#ifndef NODE_H
#define NODE_H

namespace csc195
{
	class Node
	{
	public:
		Node(int data,Node *next=0);
		Node();
		~Node();
		int getData() const;
		void setData(int data);
		Node* next;
	private:
		int data;
	};
}
#endif
