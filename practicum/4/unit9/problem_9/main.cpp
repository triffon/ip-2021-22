#include <iostream>

// Създайте функция, която връща размера на низ без да използвате оператора `[]`.

int my_strlen(const char* str) {
	int size = 0;
	while (*(str+size) != '\0') {
		size++;
	}
	return size;
}
int main() {
	char str[64];
	std::cin.getline(str, 64);
	std::cout << my_strlen(str);
	return 0;
}