#include <iostream>
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[10]{ 1, 2, 3, 15, 57, 69, 77, 80, 81, 153 };

	int x = 0;
	int a = 0;
	int b = 9;

	int what;
	cout << "Введите значение, которое нужно найти: ";
	cin >> what;

	bool found;

	for (found = false; (arr[a] < what) && (arr[b] > what) && !found;)
	{
		x = a + ((what - arr[a]) * (b - a)) / (arr[b] - arr[a]);
		if (arr[x] < what)
		{
			a = x + 1;
		}
		else if (arr[x] > what)
		{
			b = x - 1;
		}
		else
		{
			found = true;
		}
	}

	if (arr[a] == what)
	{
		cout << what << " найден в элементе с индексом " << a << endl;
	}
	else if (arr[b] == what)
	{
		cout << what << " найден в элементе с индексом " << b << endl;
	}
	else
	{
		cout << "Не найдено" << endl;
	}

}