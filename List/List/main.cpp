#include "list.h"
#include <iostream>

using namespace std;

void main()
{
	List a(5);
	a.PrintList();
	Node c(5);
	a.AddStart(c);
	a.PrintList();
	a.PrintList3();

}
