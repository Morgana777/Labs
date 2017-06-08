#include <iostream>
#include <conio.h>
#include "StackList.h"

using namespace std;
void main()
{
	StackList <int> st;
	st.Push(2);
	st.Push(8);
	st.Push(4);
	st.Push(300);
	st.Push(1);
	st.Push(30);
	
	cout << st.Pop() << endl;
		cout << st.Pop() << endl;
		cout << st.Pop() << endl;
		cout << st.Pop() << endl;
		cout << st.Pop() << endl;
		cout << st.Pop() << endl;
		
		cout << st.Max() << endl;
}