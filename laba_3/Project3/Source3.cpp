#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>
using namespace std;

int polzh(int arr[], int size) {
	int i_last = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) i_last = i;
	}
	return i_last;
}

int main() {
	int N1, N2;
	cin >> N1 >> N2;
	int* A = new int[N1];
	int* B = new int[N2];

	//заполняем массивы:
	cout << "A:";
	for (int i = 0; i < N1; i++) {
		A[i] = rand() % 20 - 10;
		cout << A[i] << " ";
	}
	cout << "\n" << "B:";
	for (int i = 0; i < N2; i++) {
		B[i] = rand() % 40 - 20;
		cout << B[i] << " ";
	}

	//находим положение последнего:
	int kA = polzh(A, N1);
	int kB = polzh(B, N2);

	//находим минимальный:
	int minA = 15;
	for (int p = 0; p < kA; p++) {
		if (A[p] < minA) minA = A[p];
	}
	int minB = 15;
	for (int m = 0; m < kB; m++) {
		if (B[m] < minB) minB = B[m];
	}
	
	cout << "\n" << minA << " " << minB;
	return 1;
}