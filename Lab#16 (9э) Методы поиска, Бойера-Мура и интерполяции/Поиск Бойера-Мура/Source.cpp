#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int BMsearch(string str, string substr)
{
	int strl, substrl, res = -1;
	strl = str.size(); substrl = substr.size();

	if (strl != 0 && substrl != 0)
	{
		int i, pos;
		int bias[256];
		for (i = 0; i < 256; i++)
		{
			bias[i] = substrl;
		}
		for (i = substrl - 2; i >= 0; i--)
		{
			if (bias[int((unsigned char)substr[i])] == substrl)
			{
				bias[int((unsigned char)substr[i])] = substrl - i - 1;
			}
		}
		pos = substrl - 1;
		while (pos < strl)
		{
			if (substr[substrl - 1] != str[pos])
			{
				pos += bias[int((unsigned char)str[pos])];
			}
			else
			{
				for (i = substrl - 1; i >= 0; i--)
				{
					if (substr[i] != str[pos - substrl + i + 1])
					{
						pos += bias[int((unsigned char)str[pos - substrl + i + 1])];
						break;
					}
					else if (i == 0)
					{
						return pos - substrl + 1;
					}
				}
			}
		}
	}
	return res;
}

struct student
{
	string fam;
	string name;
	string otch;
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	student* arr = new student[3];
	for (int i = 0; i < 3; i++)
	{
		string s1, s2, s3;
		cout << "¬ведите фамилию: "; cin >> s1;
		arr[i].fam = s1;
		cout << "¬ведите им€: "; cin >> s2;
		arr[i].name = s2;
		cout << "¬ведите отчество: "; cin >> s3;
		arr[i].otch = s3;
		cout << endl;
	}

	string what;
	cout << "¬ведите, что нужно найти: "; cin >> what;

	bool p = false;
	int h = -1;
	for (int i = 0; i < 3 && p == false; i++)
	{
		if (BMsearch(arr[i].fam, what) >= 0 || BMsearch(arr[i].name, what) >= 0 || BMsearch(arr[i].otch, what) >= 0)
		{
			cout << "Ёлемент найден." << endl;
			h = 1;
			p = true;
		}
	}

	if (h < 0)
	{
		cout << "Ёлемент не найден. " << endl;
	}

}