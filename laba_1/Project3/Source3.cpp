#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
	int a;
	scanf("%d", &a);
	int mraz[3];
	for (int i = 0; i < 3; i++)
	{
		mraz[i] = a % 10;
		a = a / 10;
		printf("%d", mraz[i]);
    }
	return 1;
}