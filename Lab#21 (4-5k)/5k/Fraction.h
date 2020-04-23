#pragma once

#include "Pair.h"

class Fraction :
	public Pair
{
public:
	Fraction(void);
public:
	~Fraction(void);
	void Show();
	Fraction(int, int);
	Fraction(const Fraction&);
	Fraction& operator=(const Fraction&);
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);
	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend istream& operator>>(istream& in, Fraction& f);
	friend ostream& operator<<(ostream& out, const Fraction& f);
};