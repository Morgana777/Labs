#ifndef _AVL_H_
#define _AVL_H_
#include <iostream>
#include <iomanip>


typedef int DataType;

struct NODE
{
	DataType key;  // ключ узла
	int value;	   // данные
	int height;     // высота поддерева
	NODE* left;
	NODE* right;
	NODE(DataType k, int val)
	{ 
		key = k; 
		value = val; 
		left = right = 0; 
		height = 1; 
	}
};

class AVLTree
{	
private:
	int   height(NODE* p);  
	int  balanceVal(NODE* p); // вычисление баланса
	void fixheight(NODE* p); // установка поля высоты

	NODE* rotateright(NODE* p); // правый поворот вокруг p
	NODE* rotateleft(NODE* q); // левый поворот вокруг q

	NODE* balance(NODE* p);            // балансировка узла p
	NODE* insert(NODE* p, DataType k, int val); // вставка ключа k с данными val в дерево с корнем p
	NODE* searchmin(NODE* p);            // поиск узла с минимальным ключом в дереве p 
	NODE* delmin(NODE* p);          // удаление узла с минимальным ключом из дерева p
	NODE* del(NODE* p, DataType k); // удаление ключа k из дерева p
	NODE* find(NODE*p, DataType k);
	void print_minElement(NODE *p, int level); // поиск минимального элемента
	void  print_dfs(NODE *p, int level);
	NODE* top;
public:

	AVLTree() :top(0){};
	void add(DataType k, int val); 
	DataType get(DataType key); 
	void del(DataType key); 
	void print();
	void minElement();

	

	
};

#endif