#include "Time.h"

Time::Time()
{
	min = 0; sec = 0;
}

Time::Time(int M, int S)
{
	min = M; sec = S;
}

Time::Time(const Time& t)
{
	min = t.min; sec = t.sec;
}

Time Time::operator =(const Time& t)
{
	if (&t == this) return *this;
	min = t.min; sec = t.sec;
	return*this;
}

Time::~Time()
{
}

ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << ":" << t.sec);
}

istream& operator>>(istream& in, Time& t)
{
	cout << "min?"; in >> t.min;
	cout << "sec?"; in >> t.sec;
	return in;
}

fstream& operator>>(fstream& fin, Time& t)
{
	fin >> t.min;
	fin >> t.sec;
	return fin;
}

fstream& operator<<(fstream& fout, const Time& t)
{
	fout << t.min << "\n" << t.sec << "\n";
	return fout;
}

Time Time::operator+(Time k)
{
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t = t + kt;
	Time temp(t / 60, t % 60);
	return temp;
}

bool operator==(const Time& c1, const Time& c2)
{
	return (c1.min == c2.min && c1.sec == c2.sec);
}

Time Time::operator+(int k)
{
	Time tmp;
	int q = (min * 60 + sec) + k;
	tmp.min = q / 60;
	tmp.sec = q % 60;
	return tmp;
}