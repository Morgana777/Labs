#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <iomanip>
using namespace std;
const int DetLen = 20;
int c = -1;
int x = -1;

class Node
{
public:
	int D;
	int L;
	Node (int s);
	Node (Node&a);
};


Node::Node(int s=0)
{
	D = s;
	//L = 0;
}

Node::Node(Node&a)
{
	D = a.D;
    //L = a.L;

}


class List
{
protected:
	int *L;// массив указателей
	Node *D; //массив элементов
	int start; // индекс, где хранится 1-ый элемент
	int end; // индеск, где хранится последний элемент
	int size;// максимально доступное кол-во элементов в списке
	int count; // текущее количество элементов
	

public:
	

	List(int s = DetLen);
	List(List&a);
	void AddStart(Node&a); // добавить элемент в начало
	void AddEnd(Node&a); // добавить элемент в конец
	 void PrintList();
	 void PrintList3(); // выводит первые 3 элемента
	 Node GetStart();
	  Node GetEnd();
	
};

List::List(int s)
{
	cout << "kolicestvo elementov" << endl;
	cin >> count;
	size=s;
	start=0;
	end=count;
	D = new Node[size];
	L = new int[size];
	cout << "vvedite List" << endl;
	for (int i = 0; i < count; i++)
	{
     scanf("%d", &D[i]);
	 L[i]=i+1;
	}
	for (int j = count; j < size; j++)
	{
		
		L[j] = -1;	
	}

}
List::List(List&a)
{
	start = a.start;
	end = a.end;
	size = a.size;
	D = new Node[size];
	L = new int[size];
	for (int i = 0; i < size; i++)
	{
		D[i] = a.D[i];
		L[i] = a.L[i];
	}

}

void List::PrintList()
{
	cout << "list" << endl;
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", D[i]);
	}
	cout << "list index" << endl;
	for (int j = 0; j < size; j++)
	{
		printf("%d\n", L[j]);
	}
}

void List::PrintList3()
{
	cout << "list" << endl;
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", D[i]);
	}
	cout << "list index" << endl;
	for (int j = 0; j < 3; j++)
	{
		printf("%d\n", L[j]);
	}
}

void List::AddStart(Node &a)
{
	for (int i = 0; i < size; i++)
	{
	
			if (L[i] == -1)

				{
					c = i;
					D[c] = a;
					start = c+1;
					L[c] = start;
					break;
				}
		
	}
}
void List::AddEnd(Node &a)
{
	for (int i = 0; i < size; i++)
	{
	
			if (L[i] == -1)

				{
					x = i;
					D[x] = a;
					end = x;
					L[end] = x;
					break;
				}
	
	}

}

Node List::GetStart()

{
	Node r=D[start];
	D[start]=-1;
	int startOld=start;
	start=L[startOld];
	L[startOld]=-1;
	return r;

}

Node List::GetEnd()
{
	int cur=start;
	Node arr = D[end];
	while (L[cur]!=end)
	{
		cur=L[cur];
	}
	D[end]=-1;
	L[end]=-1;
	end=cur;
	return arr;


}



#endif
