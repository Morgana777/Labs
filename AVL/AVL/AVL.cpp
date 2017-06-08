#include "AVL.h"
#include <iostream>
using namespace std;
int a = 100;

int AVLTree::height(NODE* p)
{
	return p ? p->height : 0;
}

int AVLTree::balanceVal(NODE* p)
{
	return height(p->right) - height(p->left);
}

void AVLTree::fixheight(NODE* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

NODE* AVLTree::rotateright(NODE* p)
{
	NODE* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}
NODE* AVLTree::rotateleft(NODE* q)
{
	NODE* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}
NODE* AVLTree::balance(NODE* p)
{
	fixheight(p);
	if (balanceVal(p) == 2)
	{
		if ( balanceVal(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if ( balanceVal(p) == -2)
	{
		if ( balanceVal(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}
NODE* AVLTree::insert(NODE* p, DataType k, int val)
{
	if (!p) return new NODE(k,val);
	if (k<p->key)
		p->left = insert(p->left, k,val);
	else
		p->right = insert(p->right, k,val);
	return balance(p);
}
NODE* AVLTree::searchmin(NODE* p)
{
	return p->left ? searchmin(p->left) : p;
}
NODE* AVLTree::delmin(NODE* p)
{
	if (p->left == 0)
		return p->right;
	p->left = delmin(p->left);
	return balance(p);
}
NODE* AVLTree::del(NODE* p, DataType k)
{
	if (!p) return 0;
	if (k < p->key)
		p->left = del(p->left, k);
	else if (k > p->key)
		p->right = del(p->right, k);
	else 
	{
		NODE* q = p->left;
		NODE* r = p->right;
		delete p;
		if (!r) return q;
		NODE* min = searchmin(r);
		min->right = delmin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}
void AVLTree::add(DataType k, int val)
{
	top = insert(top, k,val);
}


NODE* AVLTree::find(NODE*p,DataType k)
{
	if (!p)
		return NULL;
	else if (k == p->key)
		return p;
	else if (k<p->key)
		p->left = find(p->left, k);
	else if (k > p->key)
		p->right = find(p->right, k);
}

DataType AVLTree::get(DataType key) 
{
	NODE* found = find(top, key);
	return found ? found->value :NULL;
}

void AVLTree::del(DataType key) 
{
	if (key!=top->key) 
	del(top, key);
	else cout << "verhina!";

}


void AVLTree::minElement()
{
   
	cout<<"Top:("<<top->key<<";"<<top->value<<");"<<endl;
	print_minElement(top, 0);

}

void AVLTree::print_minElement(NODE *p, int level)
{
	
	if (p->left && a>=p->value)
	    print_minElement(p->left, level + 1);
		//cout << "Key:" << p->key << "; Value:" << a << endl;
		a = p->value;
		printf("%d\n", a);
	
		if (p->right)
			print_minElement(p->right, level + 1);
		


}
	
void AVLTree::print_dfs(NODE *p, int level)
{
	if (p->left)
		print_dfs(p->left, level + 1);
	cout<<"Key:"<<p->key<<"; Value:"<<p->value<<endl;
	if(p->right)
		print_dfs(p->right, level + 1);
}
void AVLTree::print()
{
	cout<<"Top:("<<top->key<<";"<<top->value<<");"<<endl;
	print_dfs(top, 0);
}