#include <iostream>

int findXY(int x, int sum, int diff) {
	if (x > 9) {
		return -1;  //error code
	}

	if (9 * (sum - x - x) == diff) { // sum - x - x (sum - x = y and x) we get the first part of the concated yx - xy
									 // and we see that everything we try can be divided by 9 => 9 * (sum - x - x) = diff
		return 10 * x + (sum - x);   // sum - x comes from x + y = 12 where x + y is sum
	}

	return findXY(x + 1, sum, diff);  //recursively try with the next X.
}

int main() {
	int sum, diff;
	std::cout << "Sum: ";
	std::cin >> sum;
	std::cout << "Diff: ";
	std::cin >> diff;

	std::cout << findXY(0, sum, diff);

	return 0;
}