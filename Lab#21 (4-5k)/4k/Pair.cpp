#include "Pair.h"

Pair::Pair(void)
{
	first = 0;
	second = 0;
}

Pair::~Pair(void)
{
}

Pair::Pair(int F, int S)
{
	first = F;
	second = S;
}

Pair::Pair(const Pair& pair)
{
	first = pair.first;
	second = pair.second;
}

void Pair::set_first(int F)
{
	first = F;
}

void Pair::set_second(int S)
{
	second = S;
}

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

bool operator==(const Pair& p1, const Pair& p2)
{
	return (p1.first == p2.first && p1.second == p2.second);
}

bool operator>(const Pair& p1, const Pair& p2)
{
	return ((p1.first > p2.first) || (p1.first == p2.first && p1.second > p2.second));
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "\nFirst: "; in >> p.first;
	cout << "\nSecond: "; in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "\nFIRST: " << p.first;
	out << "\nSECOND: " << p.second;
	out << "\n";
	return out;
}