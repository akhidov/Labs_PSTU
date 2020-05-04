#include <iostream>
#include "Student.h"
#include <windows.h>
#include "Vector.h"
#include "Dialog.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Person* a = new Person;
	a->Input();
	a->Show();

	Student* b = new Student;
	b->Input();
	b->Show();

	Vector v(10);
	Object* p = a;
	v.Add(p);
	p = b;
	v.Add(p);
	v.Show();
	v.Show1(0);
	v.Del();
	cout << "\nVector size = " << v();*/

	Dialog D;
	D.Execute();
}