/*
 * Задача 1
 * Създайте програма, която чете 3 реални числа от конзолата и извежда тяхното средноаритметично.
 */
#include <iostream>

int main() {
	float n1;
	float n2;
	float n3;

	std::cin >> n1 >> n2 >> n3;

	const float mean = (n1 + n2 + n3) / 3;
	std::cout << mean << std::endl;

	return 0;
}