#include <iostream>
#include <windows.h>

using namespace std;

struct point
{
	int data;
	point* next;
};

point* first(int d)
{
	point* pv = new point;
	pv->data = d;
	pv->next = 0;
	return pv;
}

int pop(point** top)
{
	int temp = (*top)->data;
	point* pv = *top;
	*top = (*top)->next;
	delete pv;
	return temp;
}

void print(point* top)
{
	point* q = top;
	while (q)
	{
		cout << q->data << " ";
		q = q->next;
	}
}

void push(point** top, int d)
{
	point* q;
	q = new point();
	q->data = d;
	if (top == 0)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

void delete_even(point** top)
{
	point* q = *top;
	point* prev = 0;
	while (q != 0)
	{
		if (q->data % 2 == 0)
		{
			if (q == *top)
			{
				*top = q->next;
			}
			else
			{
				prev->next = q->next;
			}
		}
		prev = q;
		q = q->next;
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	point* top = 0;
	
	push(&top, 4);
	push(&top, 7);
	push(&top, 2);
	push(&top, 8);
	push(&top, 6);

	print(top);
	cout << endl;

	delete_even(&top);
	print(top);

}