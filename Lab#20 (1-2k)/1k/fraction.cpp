#include <iostream>
#include "fraction.h"

using namespace std;

void fraction::Init(unsigned int F, unsigned int S)
{
	first = F;
	second = S;
}

void fraction::Read()
{
	cout << "\nfirst?"; cin >> first;
	cout << "\nsecond?"; cin >> second;
}

void fraction::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}

void fraction::iPart(unsigned int F, unsigned int S)
{
	if (S == 0)
	{
		cout << "Error";
	}
	else
	{
		float D = F / S;
		int C = D;
		cout << "Целая часть: " << C;
	}
	cout << endl;
}