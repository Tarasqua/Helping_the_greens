#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void maxim(int** arr, int size) {
	int k = 0;
	int f = -10;
	for (int m = 0; m < size; m++) {
		for (int n = k; n < size; n++) {
			if (abs(arr[m][n]) > f) f = abs(arr[m][n]);
		}
		cout << f << " ";
		f = -10;
		k++;
	}
}


int main() {
	setlocale(0, "");

	// ������� � ��������� ������:
	int N;
	std::cin >> N;
	int** dig = new int* [N];               // ������� 
	for (int i = 0; i < N; i++) {           // ���������
		dig[i] = new int[N];              // ������ 
	}
	int i, j;
	for (i = 0; i < N; i++) { //���������� �������
		cout << i + 1 << " /\t";
		for (j = 0; j < N; j++) {
			dig[i][j] = rand() % 20 - 10;
			cout << dig[i][j] << "\t";
		}
		cout << "\n";
	}

	// �������:
	maxim(dig, N);

	return 1;
}