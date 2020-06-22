#include "Vector.h"
#include <iostream>
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "N?"; cin >> n;
	Vector <int> v(n);
	v.Print();

	cout << "Add Max: ";
	int max = v.maxx();
	v.Add(n, max);
	v.Print();

	cout << "Del Min: ";
	v.Del();
	v.Print();

	cout << "+Srednee: ";
	v.Plussr();
	v.Print();
}