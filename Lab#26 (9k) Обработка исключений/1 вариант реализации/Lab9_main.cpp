#include "Vector.h"
#include <iostream>
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		Vector x(2);
		Vector y(7);
		cout << x;
		cout << "Номер? ";
		int i;
		cin >> i;

		cout << x[i] << endl;

		cout << y;
		y = y + 3;
		cout << y;
		cout << "Length: " << y() << endl;

		y = y - 2;
		cout << y;
	}
	catch (int)
	{
		cout << "ERROR!!!" << endl;
	}

}