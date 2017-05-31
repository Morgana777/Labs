#include "Tablica.h"
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Tablica <int, char*> a(3);
	Tablica <int, char*> b(2);
	a.Add(1, "Хомяк");
	a.Add(3, "Еда");
	a.Add(2, "Опилки");
	cout << "a" <<'\n';
    cout << a << '\n';
    a.Del (3);
	cout << "после удаления по ключу 3" << '\n';
	cout << a << '\n';
	b = a;
	cout << "b" << '\n';
	cout << b << '\n';
	a.Add(4, "Клетка");
	a.Add(5, "Поилка");
	cout << "a" << '\n';
	cout << "после добавления лишего элемента" << '\n';
	cout << a << '\n';
	TablicaSort <int, char*> c(3);
	c.Add(5, "Колесо");
	c.Add(1, "Хомяк");
	c.Add(3, "Еда");
	c.Add(2, "Опилки");
	cout << "c" << '\n';
	cout << c << '\n';
}