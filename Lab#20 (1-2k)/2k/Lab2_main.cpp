//���. ������ �20(2�) "������ � �������. ������������, ������������"
#include "student.h"
#include <iostream>
#include <windows.h>

using namespace std;

student make_student()
{
	string f, g;
	float s;
	cout << "������� ���: "; cin >> f;
	cout << "������� ������: "; cin >> g;
	cout << "������� ������� ����: "; cin >> s;
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

	student s2("������ ������� ��������", "���-19-1�", 3.9);
	s2.show();
	cout << endl;

	student s3 = s2;
	s3.set_FIO("������ ���� ��������");
	s3.set_group("���-19");
	s3.set_srball(4.3);

	print_student(s3);
	cout << endl;

	s1 = make_student();
	s1.show();

}