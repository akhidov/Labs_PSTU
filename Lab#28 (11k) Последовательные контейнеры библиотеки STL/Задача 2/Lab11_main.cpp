#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include "Time.h"

using namespace std;

typedef vector<Time>vec;

vec make_vector(int n)
{
	vec v;
	for (int i = 0; i < n; i++)
	{
		Time a;
		cout << "a?"; cin >> a;
		v.push_back(a);
	}
	return v;
}

void print_vector(vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

//1 задание
Time maxx(vec v)
{
	Time m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i];
			n = i;
		}
	return m;
}

void add_vector(vec& v, Time el)
{
	v.insert(v.begin(), el);
}

//2 задание
int minn(vec v)
{
	Time m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (m > v[i])
		{
			m = v[i];
			n = i;
		}
	return n;
}

void del_vector(vec& v, int pos)
{
	v.erase(v.begin() + pos);
}

//3 задание
Time srednee(vec v)
{
	Time s;
	for (int i = 0; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}

void plussr(vec& v)
{
	Time m = srednee(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + m;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		vector<Time> v;
		vector<Time>::iterator vi = v.begin();
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);

		Time n_max = maxx(v);
		add_vector(v, n_max);
		print_vector(v);

		cout << "Минимальный элемент под номером " << minn(v) + 1 << endl;
		del_vector(v, minn(v));
		print_vector(v);

		plussr(v);
		print_vector(v);
	}
	catch (int)
	{
		cout << "error!";
	}
}