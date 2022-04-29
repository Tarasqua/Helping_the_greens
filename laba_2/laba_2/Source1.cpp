#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int* X = new int [N];
	int max = -11;
	int kmax = 0;
	int S1 = 0;
	int S2 = 0;

	for (int i = 0; i < N; i++)
	{
		X[i] = rand() % 30 - 10;
		if (X[i] > max)
		{
			max = X[i];
			kmax = i;
		};
		std::cout << X[i] << "\n";
	}
	for (int i = kmax+1; i < N; i++)
	{
		if (X[i] > 0)
			S1 = S1 + X[i];

	}
	for (int i = 0; i <= kmax; i++)
	{
		if (X[i] < 0)
			S2 = S2 + X[i];
	}
	std::cout << S1 << " " << S2;
	return 1;
}