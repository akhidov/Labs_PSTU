//Лаб. Работа №14.1 (8э) "Одно- и двунаправленные списки"
#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

struct point
{
	char* key;
	point* next;
	point* pred;
};

point* make_point()
{
	point* p = new(point);
	p->next = 0; p->pred = 0;
	char s[50];
	cout << "Введите элемент (строку): ";
	cin >> s;
	p->key = new char[strlen(s) + 1];
	strcpy_s(p->key, strlen(s) + 1, s);
	return p;
}

point* make_list(int n)
{
	point* p, * beg, * end;
	beg = make_point();

	end = beg;
	for (int i = 1; i < n; i++)
	{
		p = make_point();
		p->pred = end;
		p->next = 0;

		end->next = p;
		end = p;
	}
	return beg;
}

void print_list(point* beg)
{
	point* p = beg;
	while (p != 0)
	{
		cout << p->key << " ";
		p = p->next;
	}
	cout << endl;
}

void insertBeg(point** beg)
{
	point* p;

	p = make_point();
	
	if (*beg == 0)
	{
		*beg = p;
	}
	else
	{
		p->pred = 0;
		p->next = *beg;
		(*beg)->pred = p;
		*beg = p;
	}
}

void insertEnd(point** beg)
{
	point* p, * tmp;

	p = make_point();

	if (*beg == 0)
	{
		p->pred = p->next = 0;
		*beg = p;
	}
	else
	{
		tmp = *beg;
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
		p->pred = tmp;
		p->next = 0;
	}
}

void insertPos(point** beg, int n, int pos)
{
	point* p, * tmp;
	tmp = *beg;
	int i = 1;

	while (i < pos - 1 && tmp != 0)
	{
		tmp = tmp->next;
		i++;
	}

	if (pos == 1)
	{
		insertBeg(beg);
	}
	else if (i == n)
	{
		insertEnd(beg);
	}
	else if (tmp != 0)
	{
		p = make_point();
		p->next = tmp->next;
		p->pred = tmp;

		if (tmp->next != 0)
		{
			tmp->next->pred = p;
		}
		tmp->next = p;
	}
	else
	{
		cout << "Ошибка." << endl;
	}
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
	cout << "Введите количество элементов: "; 
	cin >> n;

	point* f;

	f = make_list(n);
	print_list(f);

	int k;
	cout << "Задайте номер для добавления элемента: ";
	cin >> k;

	insertPos(&f, n, k);
	print_list(f);

	clear(f);
}