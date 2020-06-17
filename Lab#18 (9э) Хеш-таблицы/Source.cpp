#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>

using namespace std;

struct Table
{
	string* FIO;
	string* group;
	int rating[3];
	Table* next;
	Table* prev;
};

Table** hashs;
int coliz = 0;

Table* create_obj(string names[], string surnames[], string midlenames[], string groups[])
{
	Table* p = new Table;

	for (int i = 0; i < 3; i++)
	{
		p->rating[i] = rand() % 9;
	}

	string FIO1[6];
	int k;
	k = rand() % 9;
	FIO1[0] = surnames[k];
	k = rand() % 9;
	FIO1[1] = ' ';
	FIO1[2] = names[k];
	k = rand() % 9;
	FIO1[3] = ' ';
	FIO1[4] = midlenames[k];
	p->FIO = new string[6];
	for (int i = 0; i < 6; i++)
	{
		p->FIO[i] = FIO1[i];
	}

	string group1;
	k = rand() % 2;
	group1 = groups[k];
	p->group = new string[1];
		p->group[0] = group1;

	p->next = NULL;
	p->prev = NULL;
	return p;
}

void Print(Table* p)
{
	for (int i = 0; i < 6; i++)
	{
		cout << p->FIO[i];
	}
	cout << '\t';
	for (int i = 0; i < 3; i++)
	{
		if (i == 1) cout << ".";
		cout << p->rating[i];
	}
	cout << '\t';
		cout << p->group[0];
	cout << endl;
}

int hash_func(string key[])
{
	int h = 0;
	int k = 0;
	int* ascii = new int[key[0].length()];
	for (int i = 0; i < key[0].length(); i++)
	{
		ascii[i] = key[0][i];
		k += ascii[i];
	}
	delete[]ascii;
	ascii = new int[key[2].length()];
	for (int i = 0; i < key[2].length(); i++)
	{
		ascii[i] = key[2][i];
		k += ascii[i];
	}
	delete[]ascii;
	ascii = new int[key[4].length()];
	for (int i = 0; i < key[4].length(); i++)
	{
		ascii[i] = key[4][i];
		k += ascii[i];
	}
	delete[]ascii;
	h = -k % 50;
	return h;
}

void create_table(Table* p)
{
	int h = hash_func(p->FIO);
	cout << h << " ";
	if (hashs[h] != NULL)
	{
		hashs[h]->next = p;
		p->prev = hashs[h];
		hashs[h] = hashs[h]->next;
		Print(hashs[h]);
		coliz++;
	}
	else
	{
		hashs[h] = p;
		Print(hashs[h]);
	}
}

void search_key(string key[])
{
	int h = hash_func(key);
	cout << h << " ";
	Table* r = hashs[h];
	if (r->prev == NULL)
	{
		Print(r);
	}
	else
	{
		do
		{
			if (r->FIO[0] == key[0] && r->FIO[2] == key[2] && r->FIO[4] == key[4])
			{
				Print(r);
				return;
			}
			else
			{
				r = r->prev;
			}
		} while (r != NULL);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	string names[10] = { "Виталий","Дамир","Егор","Илья","Карен","Леонид","Николай","Святослав","Станислав","Эльдар" };
	string surnames[10] = { "Иванов","Смирнов","Попов","Соколов","Морозов","Козлов","Егоров","Степанов","Николаев","Лебедев" };
	string midlenames[10] = { "Алексеевич","Олегович","Сергеевич","Игоревич","Никитич","Михайлович","Дмитриевич","Ильич","Геннадьевич","Леонидович" };
	string groups[3] = { "КС-19-1б", "АСУ-19-2б", "РИС-19-1б" };
	Table* p = NULL;
	int n;
	cout << "Введите количество элементов таблицы(более 50): ";
	cin >> n;
	hashs = new Table * [n];
	for (int i = 0; i < n; i++)
	{
		hashs[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		p = create_obj(names, surnames, midlenames, groups);
		create_table(p);
	}
	cout << "Количество коллизий :" << coliz << endl;
	cout << "Введите ФИО:";
	string search[6];
	cin >> search[0];
	cin >> search[2];
	cin >> search[4];
	search[1] = ' '; search[3] = ' ';
	search_key(search);
}