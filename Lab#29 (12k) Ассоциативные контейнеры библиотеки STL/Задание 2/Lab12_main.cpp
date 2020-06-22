#include <iostream>
#include <map>
#include <windows.h>
#include "Time.h"

using namespace std;

typedef map<int, Time>TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	Time a;
	for (int i = 0; i < n; i++)
	{
		cout << "a?"; cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " - " << m[i] << " " << endl;
}

Time maxx(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return m;
}

int minn(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

Time srednee(TMap m)
{
	Time s = m[0];
	for (int i = 1; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();
	return s / n;
}

void plussr(TMap& v)
{
	Time m = srednee(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + m;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "N?"; cin >> n;
	map<int, Time> m = make_map(n);
	print_map(m);

	Time max = maxx(m);
	cout << "Max: " << max << endl;
	m.insert(make_pair(n, max));
	print_map(m);

	int min = minn(m);
	cout << "Min: " << m[min] << endl;
	m.erase(min);
	print_map(m);

	Time el = srednee(m);
	cout << "+Srednee: " << endl;
	plussr(m);
	print_map(m);

}