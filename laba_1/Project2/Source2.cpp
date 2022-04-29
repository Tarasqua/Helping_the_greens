#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>


int main() {
	setlocale(LC_ALL, "Russian");
	char a;
	 scanf ("%c",&a);
	 switch (a)
	 {
	 case 123:
		 printf ("фигурная скобка");
		 break;
	 case 125:
		 printf("фигурная скобка");
		 break;
	 case 91:
		 printf ("квадратная скобка");
		 break;
	 case 93:
		 printf("квадратная скобка");
		 break;
	 case 40:
		 printf("круглая скобка");
		 break;
	 case 41:
		 printf("круглая скобка");
		 break;
	 default:
		 printf("не скобка");
		 break;

	}
	 return 0;
}
