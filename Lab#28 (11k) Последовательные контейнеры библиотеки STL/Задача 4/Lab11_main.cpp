#include <iostream>
#include <stack>
#include <vector>
#include <windows.h>

using namespace std;

typedef stack<int>St;
typedef vector<int>Vec;

St make_stack(int n)
{
	St s;
	int t;
	for (int i = 0; i < n; i++)
	{
		cout << "t?"; cin >> t;
		s.push(t);
	}
	return s;
}

void print_stack(St s)
{
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

int maxx(St s)
{
	int m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() > m) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}

void Add_to_stack(St& s, int el)
{
	Vec v;
	int t = maxx(s);
	int i = 1;
	while (!s.empty())
	{
		t = s.top();
		if (i == 1) v.push_back(el);
		v.push_back(t);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}

int minn(St s)
{
	int m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}

void Delete_from_stack(St& s)
{
	Vec v;
	int m = minn(s);
	int t;
	while (!s.empty())
	{
		t = s.top();
		if (t != m) v.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

int Srednee(St s)
{
	Vec v = copy_stack_to_vector(s);
	int n = 1;
	int sum = s.top();
	s.pop();
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		n++;
	}
	s = copy_vector_to_stack(v);
	return sum / n;
}

void Plussr(St& s)
{
	int m = Srednee(s);
	Vec v;
	int t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t + m);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int t;
	St s;
	int n;
	cout << "n?"; cin >> n;
	s = make_stack(n);
	print_stack(s);

	cout << endl << "Add Max: " << endl;
	t = maxx(s);
	Add_to_stack(s, t);
	print_stack(s);

	cout << endl << "Del Min: " << endl;
	Delete_from_stack(s);
	print_stack(s);

	cout << endl << "+ Srednee: " << endl;
	Plussr(s);
	print_stack(s);
}