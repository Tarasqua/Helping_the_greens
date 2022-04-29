#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <clocale>
#include <iomanip>

using namespace std;

struct prepod
{
	char* surname;
	char* name;
	char* department;
	char* subject;
};

//�������, � ������� ������� ��������� �������:
prepod* Add(prepod* old_prepod, prepod* new_prepod, const int prepodsize, const int new_prepodsize, char* buffer, int BUFF_SIZE)
{
	for (int i = 0; i < prepodsize + new_prepodsize; i++)
	{
		//�������� �������� � ����� ���������:
		if (i < prepodsize) {

			new_prepod[i].surname = new char[strlen(old_prepod[i].surname) + 1];
			for (int j = 0; j < strlen(old_prepod[i].surname); ++j) 
			{
				new_prepod[i].surname[j] = old_prepod[i].surname[j];
			}
			new_prepod[i].surname[strlen(old_prepod[i].surname)] = '\0';
			cout << endl;

			new_prepod[i].name = new char[strlen(old_prepod[i].name) + 1];
			for (int j = 0; j < strlen(old_prepod[i].name); ++j)
			{
				new_prepod[i].name[j] = old_prepod[i].name[j];
			}
			new_prepod[i].name[strlen(old_prepod[i].name)] = '\0';
			cout << endl;

			new_prepod[i].department = new char[strlen(old_prepod[i].department) + 1];
			for (int j = 0; j < strlen(old_prepod[i].department); ++j)
			{
				new_prepod[i].department[j] = old_prepod[i].department[j];
			}
			new_prepod[i].department[strlen(old_prepod[i].department)] = '\0';
			cout << endl;

			new_prepod[i].subject = new char[strlen(old_prepod[i].subject) + 1];
			for (int j = 0; j < strlen(old_prepod[i].subject); ++j)
			{
				new_prepod[i].subject[j] = old_prepod[i].subject[j];
			}
			new_prepod[i].subject[strlen(old_prepod[i].subject)] = '\0';
			cout << endl;
		}

		//������� ����� ������:
		else if (i >= prepodsize) {
			cout << "������� ������� �������������: ";
			gets_s(buffer, BUFF_SIZE);
			new_prepod[i].surname = new char[strlen(buffer) + 1];
			for (int j = 0; j < strlen(buffer); ++j) 
			{
				new_prepod[i].surname[j] = buffer[j];
			}
			new_prepod[i].surname[strlen(buffer)] = '\0';
			cout << endl;

			cout << "������� ��� �������������: ";
			gets_s(buffer, BUFF_SIZE);
			new_prepod[i].name = new char[strlen(buffer) + 1];
			for (int j = 0; j < strlen(buffer); ++j)
			{
				new_prepod[i].name[j] = buffer[j];
			}
			new_prepod[i].name[strlen(buffer)] = '\0';
			cout << endl;

			cout << "������� �������: ";
			gets_s(buffer, BUFF_SIZE);
			new_prepod[i].department = new char[strlen(buffer) + 1];
			for (int j = 0; j < strlen(buffer); ++j)
			{
				new_prepod[i].department[j] = buffer[j];
			}
			new_prepod[i].department[strlen(buffer)] = '\0';
			cout << endl;

			cout << "������� �������: ";
			gets_s(buffer, BUFF_SIZE);
			new_prepod[i].subject = new char[strlen(buffer) + 1];
			for (int j = 0; j < strlen(buffer); ++j)
			{
				new_prepod[i].subject[j] = buffer[j];
			}
			new_prepod[i].subject[strlen(buffer)] = '\0';
			cout << endl;
		}
	}

	delete[] buffer;
	return new_prepod;
}

//������� ��� ������ �������:
void showData(const prepod* Obj, const int amount) {
	system("cls");
	cout << "� |\t " << setfill(' ') << setw(15) << "�������     " << left << " |\t " << setfill(' ') << setw(15) << "���" << left << " |\t " << setfill(' ') << setw(15) << "�������" << left << " | " << setfill(' ') << setw(15) << "�������" << left << " |" << endl;
	cout << "=====================================================================================================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1 << " |\t " << setfill(' ') << setw(15) << Obj[i].surname << left << " |\t " << setfill(' ') << setw(15) << Obj[i].name << left << " |\t " << setfill(' ') << setw(15) << Obj[i].department << left << " | " << setfill(' ') << setw(15) << Obj[i].subject << left << " |" << endl;
		cout << "=====================================================================================================================" << endl;
	}
}

//������� ��� ������ ���������:
void FindPrepod (const int prepodsize, char* surname, char* name, prepod* prepods)
{
	bool flag = false;

	for (int i = 0; i < prepodsize; ++i)
	{
		if ((strcmp(prepods[i].surname, surname) == 0) && (strcmp(prepods[i].name, name) == 0))
		{
			cout << prepods[i].subject << '\t';
			flag = true;
		}
	}

	if (flag == false) cout << "���������� �� �������!";
}

//������� ��� ������ �������� �������:
void onlyInDepartment(prepod* prepods, const int n, const int BUFF_SIZE) 
{
	char* n_department = new char[BUFF_SIZE];
	gets_s(n_department, BUFF_SIZE);
	bool flag = 0;
	int chet = 0;

	gets_s(n_department, BUFF_SIZE);
	cout << endl;

	//���� ���������� ���������� ��������:
	for (int i = 0; i < n; i++) 
	{
		if (strcmp(n_department, prepods[i].department) == 0)
		{
			++chet;

			if (chet > 0) 
			{
				flag = 1;
			}
		}
	}

	//������������ ������:
	char** napr = new char* [chet];
	for (int i = 0; i < chet; i++) 
	{
		napr[i] = new char[BUFF_SIZE];
	}

	//���������� ������ ������� ��������:
	if (flag == 1) 
	{
		for (int i = 0; i < chet; i++) 
		{
			gets_s(napr[i], BUFF_SIZE);
		}
		for (int i = 0; i < chet; i++) 
		{
			strcat(napr[i], prepods[i].surname);
			strcat(napr[i], " ");
			strcat(napr[i], prepods[i].name);
		}

		//����������:
		char cur[30];
		for (int i = 0; i < chet - 1; i++)
			for (int j = i + 1; j < chet; j++)
				if (strcmp(napr[i], napr[j]) > 0)
				{
					strcpy(cur, napr[i]);
					strcpy(napr[i], napr[j]);
					strcpy(napr[j], cur);
				}

		//����� ������:	
		cout << "� |\t " << setfill(' ') << setw(15) << "������� ���    " << left << " |\t " << setfill(' ') << setw(15) << "�������" << left << " |\t " << setfill(' ') << setw(15) << endl;
		cout << "=====================================================================================================================" << endl;
		for (int i = 0; i < chet; i++)
		{
			cout << i + 1 << " |\t " << setfill(' ') << setw(15) << napr[i] << left << " |\t " << setfill(' ') << setw(15) << n_department << left << " |\t " << setfill(' ') << setw(15) << endl;
			cout << "=====================================================================================================================" << endl;
		}
	}

	else if (flag == 0)
	{
		cout << "������ ������� �� ����������!" << endl;
	}


	delete[] napr;
}

int main() 
{
	setlocale(LC_ALL, "Rus");
	int n;

	cout << "������� ���������� ��������������: "; 
	cin >> n;
	cout << "\n";
	//---------------------------------------------------

	int BUFFER_SIZE = 50, STRNUM = 100;
	char* buff = new char[BUFFER_SIZE];
	gets_s(buff, BUFFER_SIZE);

	prepod* p = NULL;
	p = new prepod[STRNUM];
	//---------------------------------------------------

	//�������� ���� ��������������:
	for (int i = 0; i < n; ++i)
	{
		//������ �������:
		cout << "������� ������� �������������: ";
		gets_s(buff, BUFFER_SIZE);
		p[i].surname = new char[strlen(buff) + 1];
		for (int j = 0; j < strlen(buff); ++j)
		{
			p[i].surname[j] = buff[j];
		}
		p[i].surname[strlen(buff)] = '\0';
		cout << endl;

		//������ ���:
		cout << "������� ��� �������������: ";
		gets_s(buff, BUFFER_SIZE);
		p[i].name = new char[strlen(buff) + 1];
		for (int j = 0; j < strlen(buff); ++j) 
		{
			p[i].name[j] = buff[j];
		}
		p[i].name[strlen(buff)] = '\0';
		cout << endl;

		//������ �������:
		cout << "������� �������: ";
		gets_s(buff, BUFFER_SIZE);
		p[i].department = new char[strlen(buff) + 1];
		for (int j = 0; j < strlen(buff); ++j) 
		{
			p[i].department[j] = buff[j];
		}
		p[i].department[strlen(buff)] = '\0';
		cout << endl;

		//������ �������:
		cout << "������� �������: ";
		gets_s(buff, BUFFER_SIZE);
		p[i].subject = new char[strlen(buff) + 1];
		for (int j = 0; j < strlen(buff); ++j) 
		{
			p[i].subject[j] = buff[j];
		}
		p[i].subject[strlen(buff)] = '\0';
		cout << endl;
	}
	//---------------------------------------------------

	//������ � ���������:
	int choice = 0;
	int choice_n = 0;
	cout << endl << "������ ������ ��� ������������� (0 - ���, 1 - ��)?  "; cin >> choice;

	//���� ������������� �����������, �� �� �������� � ������ ����������� ��������, ������ � �������.
	if (choice == 1)
	{
		int num_prepods;
		char* buffer = new char[BUFFER_SIZE];
		cout << "������� ���������� ����� ��������������: ";
		cin >> num_prepods;
		gets_s(buffer, BUFFER_SIZE);
		prepod* nev = new prepod[n + num_prepods];
		//---------------------------------------------------
	    
		//����������:
		nev = Add(p, nev, n, num_prepods, buffer, BUFFER_SIZE);
		//---------------------------------------------------

		//����� �������:
		cout << endl << "������� �������? (1- ��, 0 - ���) " << endl;
		cin >> choice_n;
		if (choice_n == 1)
		{
			cout << endl << endl << "����� �������:" << endl;
			showData(nev, n + num_prepods);
		}
		//---------------------------------------------------

		//����� ��������� ������������� �������������:
		cout << endl << "������� �������� �������������? (0 - ���, 1 - ��)  "; cin >> choice_n;
		if (choice_n == 1)
		{
			char n_name[30];
			char n_surname[30];
			cout << endl << "������� ���: "; cin >> n_name; cout << "  ������� �������: "; cin >> n_surname;
			cout << endl << "�������� �������������: ";
			FindPrepod(n + num_prepods, n_surname, n_name, nev);
		}
		//---------------------------------------------------

		//����� � ������������ ��������:
		cout << endl << "������� �������������� �������? (0 - ���, 1 - ��)" << endl; 
		cin >> choice_n;
		if (choice_n == 1)
		{
			cout << "������� �������: ";
			onlyInDepartment(nev, n + num_prepods, 100);
		}
		//---------------------------------------------------

	}

	else
	{
		//����� �������:
		cout << endl << "������� �������? (1- ��, 0 - ���) " << endl;
		cin >> choice_n;
		if (choice_n == 1)
		{
			cout << endl << endl << "����� �������:" << endl;
			showData(p, n);
		}
		//---------------------------------------------------

		//����� ��������� ������������� �������������:
		cout << endl << "������� �������� �������������? (0 - ���, 1 - ��)  "; cin >> choice_n;
		if (choice_n == 1)
		{
			char n_name[30];
			char n_surname[30];
			cout << endl << "������� ���: "; cin >> n_name; cout << "������� �������: "; cin >> n_surname;
			cout << endl << "�������� �������������: ";
			FindPrepod(n, n_surname, n_name, p);
		}
		//---------------------------------------------------

		//����� � ������������ ��������:
		cout << endl << "������� �������������� �������? (0 - ���, 1 - ��)" << endl;
		cin >> choice_n;
		if (choice_n == 1)
		{
			cout << "������� �������: ";
			onlyInDepartment(p, n, 100);
		}
		//---------------------------------------------------

	}

	cout << endl << "���� ��������." << endl;

	return 0;
}