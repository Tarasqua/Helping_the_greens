#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main() {
	float a = 0;
	float b = 0;
	float p = 0;
	while (true) {
		scanf("%f", &a);
		scanf("%f", &b);
		if (a <= 0 || b <= 0)
			printf("False!");
		else {
			p = 2 * (a + b);
			printf("\nPerimeter =%f\n", p);
			break;
		}
	}
	system("pause");
	return 1;
}