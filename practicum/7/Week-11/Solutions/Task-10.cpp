#include <iostream>

bool contains(int n, int k) {
	if (k < 0 || k > 9) {
		return false;
	}
	while (n > 0) {
		if (n % 10 == k) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int product(int** matrix, int n) {
	int prod = 1;
	for (int i = 0; i < n; i++) {
		for (int j = n - i; j < n; j++) {
			if (contains(matrix[i][j], 1)) {
				prod *= matrix[i][j];
			}
		}
	}
	return prod;
}



int main()
{
	//Test it.

	return 0;
}