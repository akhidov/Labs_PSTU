#pragma once

#include <iostream>

using namespace std;

class Pair
{
public:
	Pair(void);
public:
	virtual ~Pair(void);
	Pair(int, int);
	Pair(const Pair&);
	int get_first() { return first; }
	int get_second() { return second; }
	void set_first(int);
	void set_second(int);
	Pair& operator = (const Pair&);
	friend bool operator==(const Pair& p1, const Pair& p2);
	friend bool operator>(const Pair& p1, const Pair& p2);
	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);
protected:
	int first;
	int second;
};