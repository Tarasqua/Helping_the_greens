#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const int N = 10, M = 12;
	double dig[N][M];
	int	i, j;
	for (i = 0; i < N; i++) { //заполнение матрицы 
		cout << i+1 << " /\t";
		for (j = 0; j < M; j++) {
			dig[i][j] = rand() % 100 - 20;
			cout << dig[i][j] << "\t";
		}
		cout << "\n";
	}

	int k = 0;
	for (i = 4; i < N; i++) { //считаем количество положительных чисел
		for (j = 0; j < M; j++) {
			if (dig[i][j] > 0) k++;
		}
	}
	cout << k << "\n";

	int p = 0; 
	for (i = 0; i < N; i++) { //считаем отрицательные
		for (j = 0; j < M; j = j + 2) {
			if (dig[i][j] < 0) p++;
		}
	}

	int *X = new int[p];
	for (i = 0; i < p; i++) {
		X[i] = rand() % 30 - 10;
		cout << X[i] << " ";
	}

}