#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

struct point
{
	string key;
	point* next;
};

point* first(string s)
{
	point* pv = new point;
	pv->key = s;
	pv->next = 0;
	return pv;
}

string add(point** pend, string s)
{
	point* pv = new point;
	pv->key = s;
	pv->next = 0;
	(*pend)->next = pv;
	*pend = pv;
	return s;
}

void print(point* pbeg)
{
	point* tmp = pbeg;
	while (tmp != 0)
	{
		cout << tmp->key << " ";
		tmp = tmp->next;
	}
}

void del(point** pbeg)
{
	point* pv = *pbeg;
	*pbeg = (*pbeg)->next;
	delete pv;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string s;
	string h[5];
	int n;
	cout << "Введите количество элементов: "; cin >> n; cout << endl;
	cout << "Введите элемент (строку): ";
	cin >> s;
	h[0]= s;
	point* pbeg = first(s);
	point* pend = pbeg;
	for (int i = 1; i < n; i++)
	{
		string d; 
		cout << "Введите элемент (строку): ";
		cin >> d;
		h[i] = d;
		add(&pend, d);
	}

	print(pbeg);
	cout << endl;

	//del(&pbeg);
	//print(pbeg);

	int k;
	cout << "Введите позицию для вставки элемента (от 0): "; cin >> k; cout << endl;

	if (k == 0)
	{
		string z;
		cout << "Введите новый элемент (строку): ";
		cin >> z;
		point* nbeg = first(z);
		point* nend = nbeg;
		for (int i = 0; i < n; i++)
		{
			add(&nend, h[i]);
		}
		print(nbeg); cout << endl;
	}
	else
	{
		point* nbeg = first(h[0]);
		point* nend = nbeg;
		for (int i = 1; i < k; i++)
		{
			add(&nend, h[i]);
		}
		string z;
		cout << "Введите новый элемент (строку): ";
		cin >> z;
		add(&nend, z);
		for (int i = k; i < n; i++)
		{
			add(&nend, h[i]);
		}
		print(nbeg); cout << endl;
	}
}