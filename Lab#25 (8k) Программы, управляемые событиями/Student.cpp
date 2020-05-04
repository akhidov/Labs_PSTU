#include "Student.h"

Student::Student(void) :Person()
{
	rating = 0;
}

Student::~Student(void)
{
}

Student::Student(string N, int A, float R) :Person(N, A)
{
	rating = R;
}

Student::Student(const Student& S)
{
	name = S.name;
	age = S.age;
	rating = S.rating;
}

void Student::Set_rating(float R)
{
	rating = R;
}

Student& Student::operator=(const Student& s)
{
	if (&s == this) return *this;
	name = s.name;
	age = s.age;
	rating = s.rating;
	return *this;
}

void Student::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
	cout << "\nRATING: " << rating;
	cout << "\n";
}

void Student::Input()
{
	cout << "\nName: "; cin >> name;
	cout << "\nAge: "; cin >> age;
	cout << "\nRating: "; cin >> rating;
}