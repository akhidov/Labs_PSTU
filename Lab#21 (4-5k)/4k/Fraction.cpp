#include "Fraction.h"

Fraction::Fraction(void) :Pair()
{
}

Fraction::~Fraction(void)
{
}

Fraction::Fraction(int F, int S) :Pair(F, S)
{
}

Fraction::Fraction(const Fraction& F)
{
	first = F.first;
	second = F.second;
}

Fraction& Fraction::operator=(const Fraction& f)
{
	if (&f == this) return *this;
	first = f.first;
	second = f.second;
	return *this;
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.first == f2.first && f1.second == f2.second);
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 == f2);
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	return ((f1.first > f2.first) || (f1.first == f2.first && f1.second > f2.second));
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return ((f1.first < f2.first) || (f1.first == f2.first && f1.second < f2.second));
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
	return ((f1.first >= f2.first) && (f1.second >= f2.second));
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
	return ((f1.first <= f2.first) && (f1.second <= f2.second));
}

istream& operator>>(istream& in, Fraction& f)
{
	cout << "\nЦелая часть: "; in >> f.first;
	cout << "\nДробная часть: "; in >> f.second;
	return in;
}

ostream& operator<<(ostream& out, const Fraction& f)
{
	out << "\nЦелая часть : " << f.first;
	out << "\nДробная часть: " << f.second;
	out << "\n";
	return out;
}