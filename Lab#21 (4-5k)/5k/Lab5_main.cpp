//���. ������ �21(5�) "������������. �����������. ����������� ������. ����������� ������"
#include "Object.h"
#include "Pair.h"
#include "Fraction.h"
#include "Vector.h"
#include <iostream>
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// �������� ������ ������ Pair
	//Pair a; 
	//cin >> a;
	//cout << a << endl;
	//Object* p = &a;
	//p->Show();

	// �������� ������ ������ Fraction
	//Fraction b;
	//cin >> b;
	//cout << b << endl;
	//p = &b;
	//p->Show();

	Vector v(5);
	Pair z;
	cin >> z;
	Fraction x;
	cin >> x;
	Object* p2 = &z;
	v.Add(p2);
	p2 = &x;
	v.Add(p2);
	cout << v;
}