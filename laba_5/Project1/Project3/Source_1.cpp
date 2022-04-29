#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <clocale>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int numOfWords(char mas[], int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (mas[i] == ' ') count++;
	}
	return count + 1;
}

char* resize(const char* str, unsigned size, unsigned new_size)
{
	char* new_str = new char[new_size];
	for (int i = 0; i < new_size; i++) {
		new_str[i] = str[i];
	}
	delete[] str;
	return new_str;
}

int main() {

	int k = 1;
	int n = 5;
	// введем и заполним массив:
	char* str = new char [n];
	while (true) {
		cin.getline(str, k);
		if (str[k] != 'done') {
			if (k == n) {
				str = resize(str, n, ++n);
				++n;
			}
			++k;
		}
		else break;
	}

	// выведем массив:
	for (int i = 0; i < k; ++i) {
		cout << str[i] << " ";
	}

	return 1;
}
