//Лаб. Работа №20(1к) "Классы и объекты. Инкапсуляция, конструкторы"
#include <iostream>
#include "fraction.h"
#include <windows.h>

using namespace std;

fraction make_fraction(unsigned int F, unsigned int S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fraction A;
	fraction B;

	A.Init(7, 3);
	B.Read();

	A.Show();
	B.Show();

	cout << endl;

	A.iPart(A.first, A.second);
	B.iPart(B.first, B.second);

}