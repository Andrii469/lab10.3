#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


#pragma pack(push, 1)

struct Shop
{
	string shop_name;
	string item_name;
	double price_for_item; 
	int amount_of_items;   
};

#pragma pack(pop)

void Fill_File(const string File_Name, int option);
void Print_File(const string File_Name);
void ItemSearch(const string File_Name, const string Item_Name);
void ShopSearch(const string File_Name, const string Shop_Name);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int action;

	string Shop_Name, Item_Name;

	string File_Name = "test.txt";

	do
	{
		cout << endl << endl;
		cout << "������� ��: " << endl;
		cout << "1 - ��������� ����" << endl;
		cout << "2 - ������� ����, �� �������� � ����" << endl;
		cout << "3 - ��������� ������" << endl;
		cout << "4 - ����� �� ������ ������" << endl;
		cout << "5 - ����� �� ������ ��������" << endl;
		cout << "0 - ��������� ������ ��������" << endl;

		cout << "������: "; cin >> action;

		cout << endl << endl;

		switch (action)
		{
		case 1:
			Fill_File(File_Name, 1);
			break;
		case 2:
			Print_File(File_Name);
			break;
		case 3:
			Fill_File(File_Name, 2);
			break;
		case 4:
			cout << "������ ����� ������: ";

			cin.get(); cin.sync();
			getline(cin, Item_Name);

			ItemSearch(File_Name, Item_Name);
			break;
		case 5:
			cout << "������ ����� ��������: ";

			cin.get(); cin.sync();
			getline(cin, Shop_Name);

			ShopSearch(File_Name, Shop_Name);
			break;
		case 0:
			exit(1);
		default:
			cout << "�������!" << endl;
		}
	} while (action != 0);

	return 0;
}
void Fill_File(const string File_Name, int option)
{
	Shop S;

	string action;

	ofstream f;

	switch (option)
	{
	case 1:
	{
		f.open(File_Name, ios::out); // ��������� ������ �����
		break;
	}
	case 2:
	{
		f.open(File_Name, ios::app); // ������������ ������� � ����� ����� 
		break;
	}
	}

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	cin.get();
	do
	{
		cout << endl << endl;
		cout << "������ ����� ��������: "; getline(cin, S.shop_name);
		f << S.shop_name << endl;

		cout << "������ ����� ������: "; getline(cin, S.item_name);
		f << S.item_name << endl;

		cout << "������ ���� ������: "; cin >> S.price_for_item;
		f << S.price_for_item << endl;

		cout << "������ ������� ������: "; cin >> S.amount_of_items;
		f << S.amount_of_items << endl;

		cin.get();
		cout << "������ ���������?(Y - ���, N - ͳ): "; getline(cin, action); cout << endl;

	} while (action == "yes" ||
		action == "Yes" ||
		action == "y" ||
		action == "Y" ||
		action == "���" ||
		action == "���" ||
		action == "��");
}
void Print_File(const string File_Name)
{
	int number = 1;

	char line[50];

	ifstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	string tmp;
	int counter = 0;

	cout << "==================================================================================" << endl;
	cout << "| � |  ����� ��������  |  ����� ������  |  ������� ������  |  ʳ������ ������  |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		getline(f, tmp);
		counter++;
	}

	f.close();
	f.open(File_Name, ios::in);

	for (int i = 0; i < counter / 4; i++)
	{
		cout << "|" << setw(2) << number++ << setw(2);

		f.getline(line, sizeof(line));
		cout << "|" << setw(10) << line << setw(9); // ����� �����

		f.getline(line, sizeof(line));
		cout << "|" << setw(10) << line << setw(7); // ����� ������

		f.getline(line, sizeof(line));
		cout << "|" << setw(10) << line << setw(9); // ���� ������

		f.getline(line, sizeof(line));
		cout << "|" << setw(10) << line << setw(12) << "|" << endl; // ������� ������		
	}

	cout << "==================================================================================" << endl;
}

void ItemSearch(const string File_Name, const string Item_Name)
{
	char line[50];

	char first_line[50];

	int number = 1;

	fstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	cout << "==================================================================================" << endl;
	cout << "| � |  ����� ��������  |  ����� ������  |  ������� ������  |  ʳ������ ������  |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		f.getline(first_line, sizeof(first_line));

		f.getline(line, sizeof(line));

		if (line == Item_Name)
		{
			cout << "|" << setw(2) << number++ << setw(2);

			cout << "|" << setw(10) << first_line << setw(9);

			cout << "|" << setw(10) << line << setw(7);

			f.getline(line, sizeof(line));
			cout << "|" << setw(10) << line << setw(9);

			f.getline(line, sizeof(line));
			cout << "|" << setw(10) << line << setw(12) << "|" << endl;
		}
		else
			for (int i = 0; i < 2; i++)
				f.getline(line, sizeof(line));
	}
	cout << "==================================================================================" << endl;
}
void ShopSearch(const string File_Name, const string Shop_Name)
{
	char line[50];

	int number = 1;

	int counter = 0;

	fstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	cout << "==================================================================================" << endl;
	cout << "| � |  ����� ��������  |  ����� ������  |  ������� ������  |  ʳ������ ������  |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		f.getline(line, sizeof(line));

		counter++;

		if (line == Shop_Name)
		{
			cout << "|" << setw(2) << number++ << setw(2);

			cout << "|" << setw(10) << line << setw(9);

			f.getline(line, sizeof(line));
			cout << "|" << setw(10) << line << setw(7);

			f.getline(line, sizeof(line));
			cout << "|" << setw(10) << line << setw(9);

			f.getline(line, sizeof(line));
			cout << "|" << setw(10) << line << setw(12) << "|" << endl;
		}
		else
			for (int i = 0; i < 3; i++)
				f.getline(line, sizeof(line));
	}
	cout << "==================================================================================" << endl;
}