#include <iostream>
#include "Time.h"

using namespace std;

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

bool operator==(const Time& c1, const Time& c2)
{
	return (c1.min == c2.min && c1.sec == c2.sec);
}


istream& operator >> (istream& in, Time& t)
{
	cout << "min?"; in >> t.min;
	cout << "sec?"; in >> t.sec;
	return in;
}

ostream& operator << (ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}