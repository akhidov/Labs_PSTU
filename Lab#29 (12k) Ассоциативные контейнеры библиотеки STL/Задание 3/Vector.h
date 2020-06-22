#pragma once
#include <iostream>
#include <map>

using namespace std;

template<class T>
class Vector
{
	map<int, T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	void Print();
	~Vector(void);

	int maxx();
	void Add(int n, T el);

	int minn();
	void Del();

	T Srednee();
	void Plussr();
};

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::~Vector(void)
{
}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cout << "a?"; cin >> a;
		v[i] = a;
	}
	len = v.size();
}

template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << i << " - " << v[i] << " " << endl;
	cout << endl;
}

template <class T>
int Vector<T>::maxx()
{
	map<int, T>::iterator  i = v.begin();
	int nom = 0, k = 0;
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

template <class T>
void Vector<T>::Add(int n, T el)
{
	v.insert(make_pair(n, el));
}

template <class T>
int Vector<T>::minn()
{
	map<int, T>::iterator  i = v.begin();
	int nom = 0, k = 0;
	int m = (*i).second;
	while (i != v.end())
	{
		if ((*i).second.get_min()!=0 && (*i).second.get_sec()!=0)
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

template <class T>
void Vector<T>::Del()
{
	int min = minn();
	cout << "Min: " << v[min] << endl;
	v.erase(min);
}

template <class T>
T Vector<T>::Srednee()
{
	int s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}

template <class T>
void Vector<T>::Plussr()
{
	T m = Srednee();
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + m;
}