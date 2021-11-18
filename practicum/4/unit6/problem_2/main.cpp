#include <iostream>

/*
	Задача 2
	Създайте програма, която пресмята сумата a0*b0 + a1*b1 + a2*b2 + ... + an-1*bn-1,
	където а и b са масиви с размер n, въведени от конзолата.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int sumproduct(int a[], int b[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}


int main() {
	const int MAX_ARRAY_SIZE = 256;
	int a[MAX_ARRAY_SIZE], b[MAX_ARRAY_SIZE];
	int n;

	std::cin >> n;
	readArr(a, n);
	readArr(b, n);
	std::cout << sumproduct(a, b, n);
	
	return 0;
}