//Лаб. Работа №20(2к) "Классы и объекты. Инкапсуляция, конструкторы"
#include "student.h"
#include <iostream>
#include <windows.h>

using namespace std;

student make_student()
{
	string f, g;
	float s;
	cout << "Введите ФИО: "; cin >> f;
	cout << "Введите группу: "; cin >> g;
	cout << "Введите средний балл: "; cin >> s;
	student t(f, g, s);
	return t;
}

void print_student(student t)
{
	t.show();
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	student s1;
	s1.show();
	cout << endl;

	student s2("Ахидов Ярослав Олегович", "ИВТ-19-1б", 3.9);
	s2.show();
	cout << endl;

	student s3 = s2;
	s3.set_FIO("Иванов Илья Иванович");
	s3.set_group("РИС-19");
	s3.set_srball(4.3);

	print_student(s3);
	cout << endl;

	s1 = make_student();
	s1.show();

}