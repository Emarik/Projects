#include "memoryman.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;
using namespace csc195;

int main()
{
	{
		LinkedList ll;
		ll.add(4);
		ll.add(13);
		ll.add(42);
		ll.add(72);

		ll.remove(1);
		int* arr = new int[ll.size()];
		ll.toArray(arr, 3);
		for (int I = 0; I < ll.size(); I++)
		{
			cout << arr[I] << endl;
		}
		delete[] arr;
	}
	print_memory();
	system("PAUSE");
}