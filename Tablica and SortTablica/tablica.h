#ifndef _TABLICA_H_
#define _TABLICA_H_
#include <iostream>
#include <iomanip>
using namespace std;


template <class T, class D>
class Tablica
{
protected:
	T *Key;
	D *Table;
	int count;
	int size;

public:
	Tablica(int size);
	virtual ~Tablica();
	virtual void Add(T key, D val);
	virtual void Del(T key);
	virtual void ChangeSize();
	D & operator [] (T key);
	Tablica  & operator = (Tablica <T, D> &a);
	friend ostream& operator<<(ostream &out, const Tablica &tb)
	{
		
		cout << "Key" << "|" << "Table" << endl;
		for (int i = 0; i < tb.count; i++)
		{
			out << tb.Key[i] << "  | " << tb.Table[i] << '\n';
		}
		return out;
	}
};


template <class T, class D>
Tablica <T, D> ::Tablica(int s)
{
	count = 0;
	size = s;
	Key = new T[size];
	Table = new D[size];
	for (int i = 0; i < size; i++)
	{
		Key[i] = 0;
		Table[i] = 0;
	}
}

template <class T, class D>
Tablica <T, D> :: ~Tablica()
{
	delete[] Key;
	delete[] Table;
}


template <class T, class D>
void Tablica <T, D> ::Add(T key, D val)
{
	count++;
	if (count > size)
		ChangeSize();
	Key[count - 1] = key;
	Table[count - 1] = val;

}

template <class T, class D>
void Tablica <T, D> ::Del(T key)
{
	for (int i = 0; i < count; i++)
		if (Key[i] == key)
		{
			for (int j = i; j < count - 1; j++)
			{
				Key[j] = Key[j + 1];
				Table[j] = Table[j + 1];
			}

			count--;
		}
}


template <class T, class D>
void Tablica <T, D> ::ChangeSize()
{
	Tablica <T, D> tmp(size);
	tmp = (*this);
	delete[] Key;
	delete[] Table;
	size = count;
	Key = new T[size];
	Table = new D[size];
	for (int i = 0; i < count - 1; i++)
	{
		Table[i] = tmp.Table[i];
		Key[i] = tmp.Key[i];
	}

}


template <class T, class D>
Tablica <T, D> & Tablica <T, D> :: operator = (Tablica <T, D> &a)
{
	count = a.count;
	size = a.size;
	delete[] Key;
	delete[] Table;
	Key = new T[size];
	Table = new D[size];
	for (int i = 0; i < count; i++)
	{
		Table[i] = a.Table[i];
		Key[i] = a.Key[i];
	}
	return *this;

}


template <class T, class D>
D & Tablica <T, D> :: operator [] (T key)
{
	for (int i = 0; i < count; i++)
	{
		if (Key[i] == key)
			return Table[i];
	}
}


/////////////////////////////////////////////////////

template <class T, class D>
class TablicaSort : public Tablica <T, D>
{

public:
	TablicaSort(int size);
	TablicaSort(const Tablica <T, D> &tb);
	~TablicaSort();
    void ChangeSizeTS();
	void Add(T key, D val);
	void Del(T key);

};

template <class T, class D>
void TablicaSort <T, D>::ChangeSizeTS()
{

}

template <class T, class D>
TablicaSort <T, D> ::TablicaSort(int s) : Tablica <T, D>(s)
{

}

template <class T, class D>
TablicaSort <T, D> :: ~TablicaSort()
{

}

template <class T, class D>
void TablicaSort <T, D> ::Add(T key, D val)
{
	if (count >= size)
	ChangeSizeTS();	 
	int i = 0; 
	int j = count;
	do
	{
		int tmp = i + (j - i) / 2;
		if ((Key[tmp] == key) || (Key[tmp - 1] < key && Key[tmp] > key) || tmp == count || Key[tmp] > key && tmp == 0)
		{
          for (int z = count; z > tmp; z--)
			{
				Key[z] = Key[z - 1];
				Table[z] = Table[z - 1];
			}
			Key[tmp] = key;
			Table[tmp] = val;
			count++;
			i = j + 1;
		}

		else if (Key[tmp] > key)
			j = tmp;
		else if (Key[tmp] < key)
			i = tmp + 1;
		
	 } 
	while (i <= j);
}


template <class T, class D>
void TablicaSort <T, D> ::Del(T key)
{
	int i = 0; int j = count;
	do
	{
		int tmp = i + (j - i) / 2;

		if (Key[tmp] == key)
		{
			for (int z = tmp; z < count - 1; z++)
			{
				Key[z] = Key[z + 1];
				Table[z] = Table[z + 1];
			}
			count--;
		}
		else if (Key[tmp] > key)
			j = tmp;
		else if (Key[tmp] < key)
			i = tmp;
	} while (i < j);

};



#endif