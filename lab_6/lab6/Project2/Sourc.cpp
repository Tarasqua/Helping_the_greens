#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <clocale>
#include <iomanip>
#include "Sourc.h"

using namespace std;

struct JapanAuto
{
	char* mark;
	char* model;
	int price;
	int power;
};

JapanAuto* Add(JapanAuto* car, const int size, char* buffer, int BUFF_SIZE)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "Введите марку автомобиля: ";
		gets_s(buffer, BUFF_SIZE);
		car[i].mark = new char[strlen(buffer) + 1];
		for (int j = 0; j < strlen(buffer); ++j)
		{
			car[i].mark[j] = buffer[j];
		}
		car[i].mark[strlen(buffer)] = '\0';
		cout << endl;

		cout << "Введите модель автомобиля: ";
		gets_s(buffer, BUFF_SIZE);
		car[i].model = new char[strlen(buffer) + 1];
		for (int j = 0; j < strlen(buffer); ++j)
		{
			car[i].model[j] = buffer[j];
		}
		car[i].model[strlen(buffer)] = '\0';
		cout << endl;

		cout << "Введите цену автомобиля: ";
		cin >> car[i].price;
		cout << endl;

		cout << "Мощность (в л/с): ";
		cin >> car[i].power;
		cout << endl;
	}

	delete[] buffer;
	return car;
}

//Функция для вывода таблицы:
void ShowData(const JapanAuto* Obj, const int amount)
{
	system("cls");
	cout << "№ |\t " << setfill(' ') << setw(15) << "Марка     " << left << " |\t " << setfill(' ') << setw(15) << "Модель" << left << " |\t " << setfill(' ') << setw(15) << "Цена" << left << " | " << setfill(' ') << setw(15) << "Мощность" << left << " |" << endl;
	cout << "=====================================================================================================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1 << " |\t " << setfill(' ') << setw(15) << Obj[i].mark << left << " |\t " << setfill(' ') << setw(15) << Obj[i].model << left << " |\t " << setfill(' ') << setw(15) << Obj[i].price << left << " | " << setfill(' ') << setw(15) << Obj[i].power << left << " |" << endl;
		cout << "=====================================================================================================================" << endl;
	}
}

//Функция для поиска марки авто:
void FindMark(const int size, char* mark, JapanAuto* cars)
{
	bool flag = false;

	for (int i = 0; i < size; ++i)
	{
		if (strcmp(cars[i].mark, mark) == 0) 
		{
			cout << cars[i].mark << '\t';
			flag = true;
		}
	}

	if (flag == false) cout << "Совпадений не найдено!";
}

int Amount(const int size, JapanAuto* cars)
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

	cout << "Введите количество автомобилей: ";
	cin >> n;
	cout << "\n";
	//---------------------------------------------------

	int BUFFER_SIZE = 50, STRNUM = 100;
	char* buff = new char[BUFFER_SIZE];
	gets_s(buff, BUFFER_SIZE);

	JapanAuto* cars = new JapanAuto[100];
	cars = Add(cars, n, buff, BUFFER_SIZE);

	ShowData(cars, n);

	cout << endl << "Ввод завершен." << endl << endl;

	return 0;
}