#include "Tablica.h"
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Tablica <int, char*> a(3);
	Tablica <int, char*> b(2);
	a.Add(1, "�����");
	a.Add(3, "���");
	a.Add(2, "������");
	cout << "a" <<'\n';
    cout << a << '\n';
    a.Del (3);
	cout << "����� �������� �� ����� 3" << '\n';
	cout << a << '\n';
	b = a;
	cout << "b" << '\n';
	cout << b << '\n';
	a.Add(4, "������");
	a.Add(5, "������");
	cout << "a" << '\n';
	cout << "����� ���������� ������ ��������" << '\n';
	cout << a << '\n';
	TablicaSort <int, char*> c(3);
	c.Add(5, "������");
	c.Add(1, "�����");
	c.Add(3, "���");
	c.Add(2, "������");
	cout << "c" << '\n';
	cout << c << '\n';
}