#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <clocale>
#include <iomanip>

using namespace std;

struct JapanAuto
{
	char* mark;
	char* model;
	char* drive;
	int price;
	int power;
};

JapanAuto* Add(JapanAuto* car, const int size, char* buffer, int BUFF_SIZE)
{
	for (int i = 0; i < size; ++i)
	{
		gets_s(buffer, BUFF_SIZE);

		cout << "������� ����� ����������: ";
		gets_s(buffer, BUFF_SIZE);
		car[i].mark = new char[strlen(buffer) + 1];
		for (int j = 0; j < strlen(buffer); ++j)
		{
			car[i].mark[j] = buffer[j];
		}
		car[i].mark[strlen(buffer)] = '\0';
		cout << endl;

		cout << "������� ������ ����������: ";
		gets_s(buffer, BUFF_SIZE);
		car[i].model = new char[strlen(buffer) + 1];
		for (int j = 0; j < strlen(buffer); ++j)
		{
			car[i].model[j] = buffer[j];
		}
		car[i].model[strlen(buffer)] = '\0';
		cout << endl;

		cout << "������� ������ ����������: ";
		gets_s(buffer, BUFF_SIZE);
		car[i].drive = new char[strlen(buffer) + 1];
		for (int j = 0; j < strlen(buffer); ++j)
		{
			car[i].drive[j] = buffer[j];
		}
		car[i].drive[strlen(buffer)] = '\0';
		cout << endl;

		cout << "������� ���� ����������: ";
		cin >> car[i].price;
		cout << endl;

		cout << "�������� (� �/�): ";
		cin >> car[i].power;
		cout << endl;

	}

	delete[] buffer;
	return car;
}

//������� ��� ������ �������:
void ShowData(const JapanAuto* Obj, const int amount)
{
	system("cls");
	cout << endl << "   Japan Auto: " << endl << endl;
	cout << "� |\t " << setfill(' ') << setw(15) << "�����     " << left << " |\t " << setfill(' ') << setw(15) << "������" << left << " |\t " << setfill(' ') << setw(15) << "������" << left << " |\t " << setfill(' ') << setw(15) << "����" << left << " | " << setfill(' ') << setw(15) << "��������" << left << " |" << endl;
	cout << "=====================================================================================================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1 << " |\t " << setfill(' ') << setw(15) << Obj[i].mark << left << " |\t " << setfill(' ') << setw(15) << Obj[i].model << left << " |\t " << setfill(' ') << setw(15) << Obj[i].drive << left << " |\t " << setfill(' ') << setw(15) << Obj[i].price << left << " | " << setfill(' ') << setw(15) << Obj[i].power << left << " |" << endl;
		cout << "=====================================================================================================================" << endl;
	}
}

//������� ��� ������ ����� ����:
void FindMark(const int size, char* mark, JapanAuto* cars)
{
	bool flag = false;

	for (int i = 0; i < size; ++i)
	{
		if (strcmp(cars[i].mark, mark) == 0)
		{
			cout << cars[i].model << '\t';
			flag = true;
		}
	}

	if (flag == false) cout << "���������� �� �������!";
}

int Amount(const int size, JapanAuto * cars)
{
	int AllPrice = 0;
	for (int i = 0; i < size; ++i)
	{
		AllPrice += cars[i].price;
	}

	return AllPrice;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;

	cout << "������� ���������� �����������: ";
	cin >> n;
	cout << "\n";
	//---------------------------------------------------

	int BUFFER_SIZE = 50, STRNUM = 100;
	char* buff = new char[BUFFER_SIZE];

	JapanAuto* cars = new JapanAuto[100];
	cars = Add(cars, n, buff, BUFFER_SIZE);

	ShowData(cars, n);

	int choice = 0;
	cout << endl << "����� ���������� ������������ �����? (1-��, 0-���)  "; cin >> choice;
	if (choice == 1)
	{
		char n_mark[30];
		cout << endl << "������� �����:  "; cin >> n_mark;
		cout << endl << "������ ����� " << n_mark << ":  ";
		FindMark(n, n_mark, cars);
		cout << endl;
	}

	cout << endl << "����� ����� ���������? (1-��, 0-���)  "; cin >> choice;
	if (choice == 1)
	{
		int total = Amount(n, cars);
		cout << endl << "����� ��������� ���� ����: " << total << endl;
	}

	cout << endl << "���� ��������." << endl << endl;

	return 0;
}