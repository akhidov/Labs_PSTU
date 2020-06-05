#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Time t;
	cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t; int i = 0;
	while (stream >> t) 
	{
		cout << t << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Time key)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Time t;
	while (stream >> t)
	{
		if (stream.eof()) break;
		i++;
		if (t == key) {}
		else { temp << t; }
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, int col, Time tt)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t; int i = 0, l = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			temp << t;
			for (int j = 0; j < col; j++)
			{
				temp << tt << endl;
				l++;
			}
		}
		else
		{
			temp << t;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, Time tt)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << tt;
	return 1;
}

int change_file(const char* f_name, Time key)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t; int i = 0, l = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;
		i++;
		if (t == key)
		{
			t = t + 90;
			temp << t;
		}
		else temp << t;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}