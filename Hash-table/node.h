#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;

bool isuse = false;


template <class KEY, class DATA>
class Node
{
protected:
	KEY k;
	DATA val;
public:
	KEY GetKey();
	DATA GetData();
	void SetKey(KEY k_);
	void SetVal(DATA val_);
	void PrintNode();
	bool isused = false;
};



template <class KEY, class DATA>
KEY Node<KEY, DATA>::GetKey()
{
	return k;
}
template <class KEY, class DATA>
DATA Node<KEY, DATA>::GetData()
{
	return val;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetKey(KEY k_)
{
	k = k_;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetVal(DATA val_)
{
	val = val_;
}

template <class KEY, class DATA>
void Node<KEY, DATA>::PrintNode()
{

	cout << k << endl;
	cout << val << endl;
}


template <class KEY, class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;//текущее число записей
	int p; // смещение
	Node<KEY, DATA> * mas; // данные
	int Hash(KEY K);
public:
	Table(int size_ = 1, int p_ = 11); // конструктор
	Table(Table& ht);
	~Table();
	Node<KEY, DATA>& operator[](KEY k_);
	Table& operator=(Table& ht);
	void Add(DATA val_, KEY k_);
	void Del(KEY k_);
	friend ostream& operator«(ostream &out, const Table &ht)
	{
		for (int i = 0; i < ht.size; i++)
			out « i « " " « ht.mas[i] « '\n';
		return out;

	}
};

template <class KEY, class DATA>
Table<KEY, DATA>::Table(int size_, int p_)
{
	size = size_;
	count = 0;
	p = p_;
	mas = new Node<KEY, DATA>[size];
}

template <class KEY, class DATA>
Table<KEY, DATA>::Table(Table& ht)
{
	size = ht.size;
	count = ht.count;
	p = ht.p;
	mas = new Node[ht.size];
	for (int i = 0; i<ht.size; ++i)
		mas[i] = ht.mas[i];

}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete[] mas;
	size = 0;
	count = 0;
}

template <class KEY, class DATA>
int Table<KEY, DATA>::Hash(KEY K)
{
	return ((int)K) % size;

}

template <class KEY, class DATA>
Node <KEY, DATA> & Table <KEY, DATA>::operator[](KEY K)
{
	int index = Hash(K);
	int HashIndex = index;
	do
	{

		if (mas[index].GetKey() == K)
			return mas[index];
		else
			index += p;
	} while (index != HashIndex)

}

template <class KEY, class DATA>
void Table<KEY, DATA>::Add(DATA val_, KEY k_)
{


	int index = Hash(k_);
	int HashIndex = index;
	do
	{

		if (mas[index].isused == false)
		{
			mas[index].SetKey(k_);
			mas[index].SetVal(val_);
			mas[index].isused = true;
			return;

		}
		else
			index += p;
	} 
	while (index != HashIndex);
	
}

template <class KEY, class DATA>
Table<KEY, DATA>& Table<KEY, DATA>::operator=(Table& ht)
{

}

template <class KEY, class DATA>
void Table<KEY, DATA>::Del(KEY k_)
{
	int index = Hash(k_);
	int HashIndex = index;
	do
	{
		if (mas[index].isuse == false)
		{
			mas[HashIndex].isuse = false;
			count--;
			return;
		}
		else
			index += p;
	} while (index != HashIndex);
}



#endif //_NODE_H_