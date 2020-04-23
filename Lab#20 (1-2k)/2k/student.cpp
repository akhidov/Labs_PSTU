#include "student.h"
#include <iostream>
#include <string>

using namespace std;

student::student()
{
	FIO = "";
	group = "";
	srball = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}

student::student(string F, string G, float S)
{
	FIO = F;
	group = G;
	srball = S;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}

student::student(const student& t)
{
	FIO = t.FIO;
	group = t.group;
	srball = t.srball;
	cout << "����������� ����������� ��� ������� " << this << endl;
}

student::~student()
{
	cout << "���������� ��� ������� " << this << endl;
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
	cout << "���: " << FIO << endl;
	cout << "������: " << group << endl;
	cout << "������� ����: " << srball << endl;
}