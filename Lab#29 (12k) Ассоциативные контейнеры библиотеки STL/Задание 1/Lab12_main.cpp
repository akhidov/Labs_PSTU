#include <iostream>
#include <map>
#include <windows.h>

using namespace std;

typedef map<int, int>TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	int a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " : " << m[i] << " " << endl;
}

int maxx(TMap v)
{
	it i = v.begin();
	int nom = 0;
	int k = 0;
	int m = (*i).second;
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
	it i = v.begin();
	int nom = 0;
	int k = 0;
	int m = (*i).second;
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

int srednee(TMap v)
{
	int s = 0;
	int nom = 0, k = 0;
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
		k++;
	}
	int n = v.size();
	return s / n;
}

void plussr(TMap& v)
{
	int m = srednee(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + m;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "N?"; cin >> n;
	TMap m = make_map(n);
	print_map(m);

	int el = maxx(m);
	cout << "Max = " << el << endl;
	m.insert(make_pair(n, el));
	print_map(m);

	int min = minn(m);
	cout << "Min = " << m[min] << endl;
	m.erase(min);
	print_map(m);

	int sredn = srednee(m);
	cout << "srednee: " << sredn << endl;
	plussr(m);
	print_map(m);
}