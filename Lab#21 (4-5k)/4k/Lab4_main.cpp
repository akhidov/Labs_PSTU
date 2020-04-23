//Лаб. Работа №21(4к) "Наследование. Полиморфизм. Абстрактные классы. Виртуальные методы"
#include <iostream>
#include "Pair.h"
#include "Fraction.h"
#include <windows.h>

using namespace std;

void f1(Pair& p)
{
	p.set_first(7);
	cout << p;
}

Pair f2()
{
	Fraction f(1, 9);
	return f;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите пару чисел А, для сравнения с парой В(3, 7): ";
	Pair a;
	cin >> a;
	cout << endl << "Введённая пара: " << a << endl;

	Pair b(3, 7);

	if (a > b)
	{
		cout << "Пара А больше чем пара В.";
	}
	else
	{
		if (a == b)
		{
			cout << "Пары A и B равны.";
		}
		else
		{
			cout << "Пара А меньше чем пара В.";
		}
	}
	cout << endl;

	cout << "Присвоим пару B паре A. Получившаяся пара А: " << endl;
	a = b;
	cout << a << endl;

	Fraction c;
	cout << endl << "Введите дробь: " << endl;
	cin >> c;

	cout << endl << "Введённая дробь: " << endl;
	cout << c;

	cout << endl << "Заменим целую часть на 7: " << endl;
	f1(c);

	cout << endl << "Подставим дробь 1/9 вместо пары А и выведем её: " << endl;
	a = f2();
	cout << a << endl << endl;

	Fraction k1, k2;
	cout << "Введите первую дробь: " << endl;
	cin >> k1; cout << endl;

	cout << "Введите вторую дробь: " << endl;
	cin >> k2; cout << endl;

	cout << "Введённые две дроби: " << endl;
	cout << k1 << k2 << endl;

	cout << "Результат сравнения введённых дробей: " << endl;
	if (k1 == k2)
	{
		cout << "Дроби равны.";
	}
	else
	{
		if (k1 > k2)
		{
			cout << "Первая дробь больше.";
		}
		else
		{
			cout << "Первая дробь меньше.";
		}
	}
	cout << endl;
}