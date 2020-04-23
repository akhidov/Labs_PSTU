#pragma once

#include <iostream>
#include <string>

using namespace std;

class student
{
	string FIO;
	string group;
	float srball;

public: 
	student();
	student(string, string, float);
	student(const student&);
	~student();
	string get_FIO();
	void set_FIO(string);
	string get_group();
	void set_group(string);
	float get_srball();
	void set_srball(float);
	void show();
};