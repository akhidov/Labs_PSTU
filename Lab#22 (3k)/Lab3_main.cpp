//Лаб. Работа №22(3к) "Перегрузка операций"
#include <iostream>
#include "Time.h"
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time a;
	Time b;
	Time c;
	Time d;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "d = "; cin >> d;
	
	cout << endl;

	c = a + b;

	cout << "c = d?" << endl;
	if (c == d)
	{
		cout << "Они равны. ";
	}
	else
	{
		cout << "Они не равны. ";
	}

}