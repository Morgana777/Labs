#include "QueueList.h"
#include <iostream>

using namespace std;

void main()
{
	QueueL<int> list;

		list.add(9);
		list.add(2);
		list.add(3);
		list.add(5);
		list.add(7);
		cout << list << endl;

}