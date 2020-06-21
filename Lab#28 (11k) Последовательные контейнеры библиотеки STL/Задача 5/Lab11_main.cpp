#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector<int> v(3);
	v.Print();

	cout << endl << "Add Max: "; 
	int t = v.maxx();
	v.Add(t);
	v.Print();

	cout << endl << "Del Min: ";
	v.Del();
	v.Print();

	cout << endl << "+Srednee: ";
	v.Plussr();
	v.Print();
}