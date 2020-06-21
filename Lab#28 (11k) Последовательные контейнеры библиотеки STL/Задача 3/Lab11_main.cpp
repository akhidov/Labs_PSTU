#include "Vector.h"
#include <windows.h>
#include <iostream>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector<int>vec(5);
	vec.Print();

	int m, tmp; 
	
	m = vec.maxx();
	vec.Add(m);
	vec.Print();

	cout << "Минимальный элемент под номером " << vec.minn() + 1 << endl;
	vec.Del(vec.minn());
	vec.Print();

	vec.Srednee();
	vec.Plussr();
	vec.Print();
}