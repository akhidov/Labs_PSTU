#include <iostream>
#include <windows.h>

using namespace std;

struct point
{
	char data;
	point* left;
	point* right;
};

point* Tree(int n, point* p)
{
	point* r;
	int nl, nr;

	if (n == 0)
	{
		p = 0; 
		return p;
	}

	nl = n / 2;
	nr = n - nl - 1;
	r = new point;
	cout << "?";
	cin >> r->data;
	r->left = Tree(nl, r->left);
	r->right = Tree(nr, r->right);
	p = r;

	return p;
}

void print_tree(point* p, int lvl)
{
	if (p)
	{
		print_tree(p->left, lvl);
		cout << p->data << "  ";
		print_tree(p->right, lvl);
	}
}

void findkey(point* p, int& count, char key)
{
	if (p)
	{
		if (p->data == key)
			count = count + 1;
		findkey(p->left, count, key);
		findkey(p->right, count, key);
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	point* pbeg = 0;

	cout << "Введите количество элементов: ";
	cin >> n;

	pbeg = Tree(n, pbeg);
	cout << endl;

	print_tree(pbeg, 0);
	cout << endl;

	int count = 0;
	char key;
	cout << "Введите ключ: ";
	cin >> key;

	findkey(pbeg, count, key);
	cout << "Элементов по ключу найдено: " << count << endl;

}