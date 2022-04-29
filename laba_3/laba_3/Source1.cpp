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
	int A[10] = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10 };
	int last_n = 10;
	while ((polzh(A, last_n) != -1) and (last_n > 1)) {
		last_n = polzh(A, last_n);
		cout << last_n;
	}
}