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
		 printf ("�������� ������");
		 break;
	 case 125:
		 printf("�������� ������");
		 break;
	 case 91:
		 printf ("���������� ������");
		 break;
	 case 93:
		 printf("���������� ������");
		 break;
	 case 40:
		 printf("������� ������");
		 break;
	 case 41:
		 printf("������� ������");
		 break;
	 default:
		 printf("�� ������");
		 break;

	}
	 return 0;
}
