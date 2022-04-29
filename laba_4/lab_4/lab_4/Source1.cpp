#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void negative(int** arr, int size1,int size2) {
	int min = 100;
	int num = 0;
	int p = 0;

	int k;
	if (size2 % 2 == 0) { k = size2 / 2; }
	else { k = (size2 / 2) + 1; }

	int* X = new int[k];
	for (int j = 0; j < size2; j++) {
		if (j % 2 == 0) {
			for (int i = 0; i < size1; i++) {
				if (arr[i][j]<0) p++;
			};
			X[num] = p;
			num++;
			p = 0;
		}
	}
	for (int p = 0; p < k; p++) {
		cout << X[p] << " ";
	}
}


int main() {
	setlocale(0, "");

	// создаем и заполняем массив:
	int N, M;
	std::cin >> N >> M;
	int** dig = new int* [N];               // создаем 
	for (int i = 0; i < N; i++) {           // двумерный
		dig[i] = new int[M];              // массив 
	}


	int i, j;
	for (i = 0; i < N; i++) { //заполнение массива
		for (j = 0; j < M; j++) {
			dig[i][j] = rand() % 20 - 10;
			cout << dig[i][j] << "\t";
		}
		cout << "\n";
	}

	//функция:
	cout << endl;
	negative(dig, N, M);

	return 1;
}
