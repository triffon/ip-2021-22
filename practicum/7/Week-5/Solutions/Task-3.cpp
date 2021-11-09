#include <iostream>

int main()
{
	//Task 3. Да се изведе следната "фигура" на конзолата, по въведено `n`:
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= (n - i); k++) {
			std::cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			std::cout << "#";
		}
		std::cout << '\n';
	}
}