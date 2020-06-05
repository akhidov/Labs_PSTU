#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	Time t, t1, key;
	int k, c;
	char file_name[30];
	do
	{
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Can't make file";
			break;
		case 2: cout << "file name?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Empty file\n";
			if (k < 0) cout << "Can't read file\n";
			break;
		case 3: cout << "file name?"; cin >> file_name;
			cout << "key?"; cin >> key;
			k = del_file(file_name, key);
			if (k < 0) cout << "Can't read file";
			break;
		case 4: cout << "file name?"; cin >> file_name;
			int nom; cout << "nom?"; cin >> nom;
			int col; cout << "col?"; cin >> col;
			cout << "New time: "; cin >> t1;
			k = add_file(file_name, nom, col, t1);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name, t1);
			break;
		case 5: cout << "file name?"; cin >> file_name;
			cout << "key?"; cin >> key;
			k = change_file(file_name, key);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		}
	} while (c != 0);

}
