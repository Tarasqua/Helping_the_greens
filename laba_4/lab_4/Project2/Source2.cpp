#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void taras(int** arr, int size1, int size2) {
	int k;
	if (size1 % 2 == 0) { k = size1 / 2; }
	else { k = (int)(size1 / 2) + 1; };

	if (size1 == 1) { k = 0; };
 
	int kpol = 0, kotr = 0;
	for (int i = k; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr[i][j] > 0) { kpol++; }
			else { kotr++; }
		}
	}
	cout << "positive: " << kpol << ", negative: " << kotr;
}

int main() {
	setlocale(0, "");

	// ������� � ��������� ������:
	int N, M;
	std::cin >> N >> M;
	int** dig = new int* [N];               // ������� 
	for (int i = 0; i < N; i++) {           // ���������
		dig[i] = new int[M];              // ������ 
	}


	int i, j;
	for (i = 0; i < N; i++) { //���������� �������
		for (j = 0; j < M; j++) {
			dig[i][j] = rand() % 20 - 10;
			cout << dig[i][j] << "\t";
		}
		cout << "\n";
	}

	//�������:
	cout << endl;
	taras(dig, N, M);

	return 1;
}