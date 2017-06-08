#ifndef _QUEUELIST_H_
#define _QUEUELIST_H_

#include <iostream>

using namespace std;


template <class T>
struct TElem
{
	TElem <T> *prev, *next;

	T Val;
};

template <class T>
class QueueL
{
private:

	TElem <T> *head, *tail;

public:

	QueueL();
	void add(T);
	void print();
	T get();
	~QueueL();


friend ostream & operator<<(ostream &out, QueueL &mt)
{
	int a = 100;
	if(mt.head!=0)
		for (TElem <T> *i = mt.head; i != 0; i = i->next)
		{
			if (i->Val && a > i->Val)
			{
				//out << i->Val << endl;

					a = i->Val;	
			}

			else
				cout << a << endl;
		}
	return out;
	
}
};

template<class T>
QueueL<T>::QueueL()
{
	head = 0;
	tail = 0;
}

template<class T>
void QueueL<T>::add (T s)
{
	if (head == 0)
	{
		head= tail = new TElem <T>;
		tail->Val = s;
	}
	else
	{
		TElem <T> *temp = tail;
		tail = new TElem <T>;
		tail->prev = temp;
		temp->next = tail;
		tail->Val = s;
	}
}

template<class T>
T QueueL<T>::get()
{
	if (head == 0)
		throw 7;
	T temp = head->Val;
	TElem <T> *temp1 = head;
	head = head->next;
	head->prev = 0;
	delete temp1;
	return temp;
}

template<class T>
QueueL <T>::~QueueL()
{
	TElem <T> *f = head;
	while (f != 0)
	{
		head = f;
		f = head->next;
		delete head;
	}
}

#endif
