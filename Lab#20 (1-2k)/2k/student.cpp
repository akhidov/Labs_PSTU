#include "student.h"
#include <iostream>
#include <string>

using namespace std;

student::student()
{
	FIO = "";
	group = "";
	srball = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}

student::student(string F, string G, float S)
{
	FIO = F;
	group = G;
	srball = S;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

student::student(const student& t)
{
	FIO = t.FIO;
	group = t.group;
	srball = t.srball;
	cout << "Конструктор копирования для объекта " << this << endl;
}

student::~student()
{
	cout << "Деструктор для объекта " << this << endl;
}

string student::get_FIO()
{
	return FIO;
}

string student::get_group()
{
	return group;
}

float student::get_srball()
{
	return srball;
}

void student::set_FIO(string F)
{
	FIO = F;
}

void student::set_group(string G)
{
	group = G;
}

void student::set_srball(float S)
{
	srball = S;
}

void student::show()
{
	cout << "ФИО: " << FIO << endl;
	cout << "Группа: " << group << endl;
	cout << "Средний балл: " << srball << endl;
}