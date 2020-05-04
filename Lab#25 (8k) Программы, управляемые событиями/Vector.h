#pragma once
#include "Student.h"
#include "Event.h"

class Vector
{
public:
	Vector(int);
public:
	~Vector(void);
	void Add(Object* p);
	void Add();
	void Del();
	void Show();
	void Show1(int);
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};