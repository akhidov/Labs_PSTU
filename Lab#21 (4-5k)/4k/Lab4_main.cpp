//���. ������ �21(4�) "������������. �����������. ����������� ������. ����������� ������"
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

	cout << "������� ���� ����� �, ��� ��������� � ����� �(3, 7): ";
	Pair a;
	cin >> a;
	cout << endl << "�������� ����: " << a << endl;

	Pair b(3, 7);

	if (a > b)
	{
		cout << "���� � ������ ��� ���� �.";
	}
	else
	{
		if (a == b)
		{
			cout << "���� A � B �����.";
		}
		else
		{
			cout << "���� � ������ ��� ���� �.";
		}
	}
	cout << endl;

	cout << "�������� ���� B ���� A. ������������ ���� �: " << endl;
	a = b;
	cout << a << endl;

	Fraction c;
	cout << endl << "������� �����: " << endl;
	cin >> c;

	cout << endl << "�������� �����: " << endl;
	cout << c;

	cout << endl << "������� ����� ����� �� 7: " << endl;
	f1(c);

	cout << endl << "��������� ����� 1/9 ������ ���� � � ������� �: " << endl;
	a = f2();
	cout << a << endl << endl;

	Fraction k1, k2;
	cout << "������� ������ �����: " << endl;
	cin >> k1; cout << endl;

	cout << "������� ������ �����: " << endl;
	cin >> k2; cout << endl;

	cout << "�������� ��� �����: " << endl;
	cout << k1 << k2 << endl;

	cout << "��������� ��������� �������� ������: " << endl;
	if (k1 == k2)
	{
		cout << "����� �����.";
	}
	else
	{
		if (k1 > k2)
		{
			cout << "������ ����� ������.";
		}
		else
		{
			cout << "������ ����� ������.";
		}
	}
	cout << endl;
}