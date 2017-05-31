#include "node.h"

#include <iostream>
using namespace std;

void main()
{
	Node<int, int> a;
	Node<int, int> b;
	a.SetKey(2);
	a.SetVal(5);
	b.SetKey(1);
	b.SetVal(7);
	a.PrintNode();
	b.PrintNode();
	Table<int, int> Z;

}