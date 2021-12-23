#include <iostream>

void swap(int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}

void swap(int &a, int &b) {
	int x = a;
	a = b;
	b = x;
}

void sort(int &a, int &b, int &c) {
	if (a > c) {
		swap(a, c);
	}
	if (a > b) {
		swap(a, b);
	}
	// Вече а е най-малкото число => единствената възможна инверсия е при b и c
	if (b > c) {
		swap(b, c);
	}
}

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	sort(a, b, c);
	std::cout << a << " " << b << " " <<c;

	return 0;
}