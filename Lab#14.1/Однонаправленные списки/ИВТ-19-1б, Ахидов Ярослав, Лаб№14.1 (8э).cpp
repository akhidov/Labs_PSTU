//Лаб. Работа №14.1 (8э) "Одно- и двунаправленные списки"
#include <iostream>
#include <windows.h>

using namespace std;

struct point
{
	int data;
	point* next;
};

point* make_list(int n)
{
	point* beg;
	point *p, *r;
	beg = new(point);
	cout << "\nВведите элемент: ";
	cin >> beg->data;
	beg->next = 0;
	
	p = beg;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(point);
		cout << "\nВведите элемент: ";
		cin >> r->data;
		r->next = 0;
		p->next = r;
		p = r;
	}
	return beg;
}

void print_list(point* beg)
{
	point* p = beg;
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}

void remove_ev(point** beg)
{
	point* p = *beg;
	point* s;

	while (p != 0 && p->data % 2 == 0)
	{
		p = p->next;
	}

	*beg = p;

	if (p == 0)
	{
		return;
	}

	s = p;
	p = p->next;

	while (p != 0)
	{
		if (p->data % 2 != 0)
		{
			s->next = p;
			s = p;
		}
		p = p->next;
	}
	s->next = 0;
}

void clear(point* beg)
{
	point* p = beg;

	while (p)
	{
		beg = p->next;
		delete p;
		p = beg;
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите количество элементов списка: "; 
	cin >> n;

	point* f = 0;

	f = make_list(n);
	print_list(f);
	
	cout << endl;

	remove_ev(&f);
	print_list(f);

	clear(f);
}