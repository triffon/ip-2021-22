#include <iostream>
#include <string>

void print_permutation(char* str, int i, int size) {
	if (i == size - 1) {
		std::cout << str << std::endl;
		return;
	}

	//rat, i = 2, j = 0
	for (int j = i; j < size; ++j) {
		std::swap(str[i], str[j]); // rat
		print_permutation(str, i + 1, size); //
		std::swap(str[i], str[j]);
	}
}

//meow -> mwoe moew

int main() {
	char str[] = "meow";

	print_permutation(str, 0, strlen(str));

	return 0;
}