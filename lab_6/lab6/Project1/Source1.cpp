#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <clocale>
#include <iomanip>
#include <fstream>

using namespace std;

//исходная структура:
struct prepod
{
	char* surname;
	char* name;
	char* department;
	char* subject;
	prepod* next;
};

//Функция для добавления первоначального препода в список ():
prepod* makePrepod(char* surname, char* name, char* department, char* subject)
{
	prepod* t;
	t = new prepod;
	t->surname = surname;
	t->name = name;
	t->department = department;
	t->subject = subject;

	t->next = NULL;
	return t;
}

//Функция для вывода препода в окно вывода:
void showPrepod(prepod* begin)
{
	int i = 0;
	prepod* Cur;    // указатель на текущий узел
	cout << "№ |\t " << setfill(' ') << setw(15) << "Фамилия       " << left << " |\t " << setfill(' ') << setw(15) << "Имя" << left << " |\t " << setfill(' ') << setw(15) << "Кафедра" << left << " | " << setfill(' ') << setw(15) << "Предмет" << left << " |" << endl;
	cout << "=====================================================================================================================" << endl;
	for (Cur = begin; Cur->next != NULL; Cur = Cur->next) {
		cout << i + 1 << " |\t " << setfill(' ') << setw(15) << Cur->surname << left << " |\t " << setfill(' ') << setw(15) << Cur->name << left << " |\t " << setfill(' ') << setw(15) << Cur->department << left << " | " << setfill(' ') << setw(15) << Cur->subject << left << " |" << endl;
		cout << "=====================================================================================================================" << endl;
		i++;
	}
	cout << i + 1 << " |\t " << setfill(' ') << setw(15) << Cur->surname << left << " |\t " << setfill(' ') << setw(15) << Cur->name << left << " |\t " << setfill(' ') << setw(15) << Cur->department << left << " | " << setfill(' ') << setw(15) << Cur->subject << left << " |" << endl;// печать данных последнего узла
}

//Функция для добавления препода в список ():
void addPrepod(char* surname, char* name, char* department, char* subject, prepod* begin)
{
	prepod* New;            // указатель для нового узла
	prepod* Cur;            // рабочий указатель 
// создаем новый узел не связанный со списком
	New = new prepod;// память для нового узла
	New->surname = surname;
	New->name = name;
	New->department = department;
	New->subject = subject;// запись данных
	New->next = NULL;// узел будет последним
// поиск последнего узла в списке
	Cur = begin; // рабочий указатель в начало
	while (Cur->next != NULL) Cur = Cur->next;// перемещение на следующий узел
	Cur->next = New;
}

//Функция для поиска информации о преподавателе:
void FindPrepod(prepod* begin)
{
	int BUFF_SIZE = 100;
	cout << "Введите фамилию преподавателя: ";
	char* new_surname = new char[BUFF_SIZE];
	gets_s(new_surname, BUFF_SIZE);
	cout << endl;

	cout << "Введите имя преподавателя: ";
	char* new_name = new char[BUFF_SIZE];
	gets_s(new_name, BUFF_SIZE);
	cout << endl;

	bool flag = false;
	prepod* Cur = new prepod;
	int i = 0;
	Cur = begin;
	while (Cur->next != NULL) 
	{
		if ((strcmp(Cur->surname, new_surname) == 0) && (strcmp(Cur->name, new_name) == 0))
		{
			cout << i + 1 << " |\t " << setfill(' ') << setw(15) << Cur->surname << left << " |\t " << setfill(' ') << setw(15) << Cur->name << left << " |\t " << setfill(' ') << setw(15) << Cur->department << left << " | " << setfill(' ') << setw(15) << Cur->subject << left << " |" << endl;
			i++;
			flag = true;
		}
		Cur = Cur->next;
	}

	if (flag == false) cout << "Данного преподавателя не найдено!";
}

//Функция для поиска преподавателей определенной кафедры:
prepod* OnlyInDep(prepod* begin, prepod* Head)
{
	int BUFF_SIZE = 100;
	bool flag = 0;
	prepod* Cur = new prepod;

	cout << "Введите кафедру: ";
	char* gg = new char[BUFF_SIZE];
	gets_s(gg, BUFF_SIZE);
	Cur = Head;

	for (Cur = Head; Cur->next != NULL; Cur = Cur->next)
	{
		if (flag == 0) 
		{
			if (strcmp(gg, Cur->department) == 0) 
			{
				begin = makePrepod(Cur->surname, Cur->name, Cur->department, Cur->subject);
				flag = 1;
			}
		}

		else if (flag == 1)
		{
			if (strcmp(gg, Cur->department) == 0) 
			{
				addPrepod(Cur->surname, Cur->name, Cur->department, Cur->subject, begin);
			}
		}
	}
	return begin;
}

//Функция для добавления преподавателя:
prepod* AddToFront(prepod **begin)
{
	int BUFF_SIZE = 100;

	cout << "Введите фамилию преподавателя: ";
	char* new_surname = new char[BUFF_SIZE];
	gets_s(new_surname, BUFF_SIZE);
	cout << endl;

	cout << "Введите имя преподавателя: ";
	char* new_name = new char[BUFF_SIZE];
	gets_s(new_name, BUFF_SIZE);
	cout << endl;

	cout << "Введите кафедру: ";
	char* new_dep = new char[BUFF_SIZE];
	gets_s(new_dep, BUFF_SIZE);
	cout << endl;

	cout << "Введите предмет: ";
	char* new_sub = new char[BUFF_SIZE];
	gets_s(new_sub, BUFF_SIZE);
	cout << endl;

	prepod* ptr = new prepod;
	ptr->surname = new_surname;
	ptr->name = new_name;
	ptr->department = new_dep;
	ptr->subject = new_sub;

	ptr->next = *begin;
	*begin = ptr;

	return *begin;
}

//Функция для удаления:
void Delete(prepod** begin)
{
	int BUFF_SIZE = 100;

	cout << "Введите фамилию преподавателя: ";
	char* new_sur = new char[BUFF_SIZE];
	gets_s(new_sur, BUFF_SIZE);
	cout << endl;

	cout << "Введите имя преподавателя: ";
	char* new_name = new char[BUFF_SIZE];
	gets_s(new_name, BUFF_SIZE);
	cout << endl;

	cout << "Введите кафедру: ";
	char* new_dep = new char[BUFF_SIZE];
	gets_s(new_dep, BUFF_SIZE);
	cout << endl;

	cout << "Введите предмет: ";
	char* new_sub = new char[BUFF_SIZE];
	gets_s(new_sub, BUFF_SIZE);
	cout << endl;

	if (*begin == NULL) {
		return;
	}

	prepod* t = *begin;
	if ((strcmp(t->surname, new_sur) == 0) && (strcmp(t->name, new_name) == 0) && (strcmp(t->department, new_dep) == 0) && (strcmp(t->subject, new_sub) == 0))
	{
		*begin = t->next;
		delete t;
		return;
	}

	prepod* t1 = t->next;
	while (t1) {
		if ((strcmp(t1->surname, new_sur) == 0) && (strcmp(t1->name, new_name) == 0) && (strcmp(t1->department, new_dep) == 0) && (strcmp(t->subject, new_sub) == 0))
		{
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

//Функция для вывода на диск:
void ShowDisk(prepod* begin) 
{
	string fname = "D:/taras.txt";
	ofstream tf(fname);
	int i = 0;
	prepod* Cur;

	if (!tf) 
	{
		cout << "Open error" << endl;
		exit(1);
	}
	else cout << "Вывод на диск успешен." << endl;

	tf << "№ |\t " << setfill(' ') << setw(15) << "Фамилия       " << left << " |\t " << setfill(' ') << setw(15) << "Имя" << left << " |\t " << setfill(' ') << setw(15) << "Кафедра" << left << " | " << setfill(' ') << setw(15) << "Предмет" << left << " |" << endl;
	tf << "=====================================================================================================================" << endl;

	for (Cur = begin; Cur->next != NULL; Cur = Cur->next) 
	{
		tf << i + 1 << " |\t " << setfill(' ') << setw(15) << Cur->surname << left << " |\t " << setfill(' ') << setw(15) << Cur->name << left << " |\t " << setfill(' ') << setw(15) << Cur->department << left << " | " << setfill(' ') << setw(15) << Cur->subject << left << " |" << endl;
		tf << "=====================================================================================================================" << endl;
		i++;
	}

	tf << i + 1 << " |\t " << setfill(' ') << setw(15) << Cur->surname << left << " |\t " << setfill(' ') << setw(15) << Cur->name << left << " |\t " << setfill(' ') << setw(15) << Cur->department << left << " | " << setfill(' ') << setw(15) << Cur->subject << left << " |" << endl;
}

//Функция для добавления на диск:
prepod* AddDisk(prepod* begin) 
{
	bool flag = 0;
	char* s = new char[100];
	char* str = new char[200];
	int n = 0;

	string fname = "D:/name.txt";
	string fsurname = "D:/surname.txt";
	string fdep = "D:/department.txt";
	string fsub = "D:/subject.txt";
	ifstream cin(fsurname);

	while (!cin.eof())
	{
		cin.getline(s, 100, '\n');
		n++;
	}

	cin.close();
	delete[] s;

	ifstream infSur(fsurname);
	ifstream infName(fname);
	ifstream infDep(fdep);
	ifstream infSub(fsub);
	prepod* p = new prepod[n];

	for (int i = 0; i < n; i++) 
	{
		//вводим фамилию
		infSur.getline(str, 200, '\n');
		int len = strlen(str);
		p[i].surname = new char[strlen(str) + 1];
		for (int j = 0; j < strlen(str); ++j) {
			p[i].surname[j] = str[j];
		}
		p[i].surname[strlen(str)] = '\0';

		//вводим имя:
		infName.getline(str, 200, '\n');
		p[i].name = new char[strlen(str) + 1];
		for (int j = 0; j < strlen(str); ++j) {
			p[i].name[j] = str[j];
		}
		p[i].name[strlen(str)] = '\0';

		//вводим кафедру:
		infDep.getline(str, 200, '\n');
		p[i].department = new char[strlen(str) + 1];
		for (int j = 0; j < strlen(str); ++j) {
			p[i].department[j] = str[j];
		}
		p[i].department[strlen(str)] = '\0';

		//вводим предмет:
		infSub.getline(str, 200, '\n');
		p[i].subject = new char[strlen(str) + 1];
		for (int j = 0; j < strlen(str); ++j) {
			p[i].subject[j] = str[j];
		}
		p[i].subject[strlen(str)] = '\0';
	}

	for (int i = 0; i < n; i++) 
	{
		if (flag == 0) 
		{
			begin = makePrepod(p[i].surname, p[i].name, p[i].department, p[i].subject);
			flag = 1;
		}
		else if (flag == 1)
		{
			addPrepod(p[i].surname, p[i].name, p[i].department, p[i].subject, begin);
		}
	}

	infSur.close();
	infName.close();
	infDep.close();
	infSub.close();
	delete[] str;

	return begin;
}

prepod* Sort(prepod* begin) 
{
	prepod* q, * out = NULL, * p, * pr; 

	while (begin != NULL) 
	{ 
		q = begin; begin = begin->next; 
		for (p = out, pr = NULL; p != NULL && strcmp(q->surname, p->surname) > 0; pr = p, p = p->next);
		if (pr == NULL) 
		{ 
			q->next = out; out = q; 
		} 
		else 
		{
			q->next = p; pr->next = q;
		} 
	}

	return out;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int BUFFER_SIZE = 50, STRNUM = 100;
	char* buff = new char[BUFFER_SIZE];

	prepod* begin = NULL;
	prepod* head = NULL;

	//Считывание с диска:
	begin = AddDisk(begin);
	//------------------------------------------------------------

	cout << "   ДОБАВЛЕНИЕ НОВОГО ПРЕПОДАВАТЕЛЯ" << endl << endl;
		begin = AddToFront(&begin);
		system("cls");
	//------------------------------------------------------------

	cout << "   УДАЛЕНИЕ ПРЕПОДАВАТЕЛЯ" << endl << endl;
		Delete(&begin);
		system("cls");
	//------------------------------------------------------------

	cout << "   ВЫВОД ИНФОРМАЦИИ О ПРЕПОДАВАТЕЛЕ" << endl << endl;
		FindPrepod(begin);
		cout << endl << endl;
	//------------------------------------------------------------
	 
	cout << "   ВЫВОД ПРЕПОДАВАТЕЛЕЙ ОПРЕДЕЛЕННОЙ КАФЕДРЫ" << endl << endl;
	head = OnlyInDep(head, begin);
	showPrepod(head);
	cout << endl << endl;
	//------------------------------------------------------------

	//Сортировка по фамилии:
	begin = Sort(begin);
	//------------------------------------------------------------

	//Вывод данных на экран и на диск:
	ShowDisk(begin);
	cout << endl << endl << endl;
	cout << "   ВЫВОД ВСЕХ ПРЕПОДАВАТЕЛЕЙ КАФЕДРЫ" << endl << endl;
	showPrepod(begin);
	//------------------------------------------------------------

	return 0;
}