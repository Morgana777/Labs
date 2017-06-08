#include "AVL.h"
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	AVLTree tree;
	tree.add(1, 10);
	tree.add(2, 5);
	tree.add(3, 1);
	tree.add(4, 40);
	tree.add(5, 850);


	cout << "Tree" << endl;
	tree.print();
	//cout << "Del element" << endl;
	//tree.del(5);
	//tree.print();
	/*cout << "Search" << endl;
	cout << tree.get(6)<<endl;*/

	tree.minElement();
}