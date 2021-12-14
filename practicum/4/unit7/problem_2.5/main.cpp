/*
 * Задача 2.5
 * Създайте програма, която извежда броя на думите в низ, въведен от потребителя(разделителите между отделните думи са интервал,
 * табулация и символ за нов ред)
 */

#include <iostream>

bool isSeparator(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}


int wordsCount(const char str[]) {
	int count = 0;
	// Нова дума започва, ако:
	// а) Текущият символ е първи и не е разделител.
	// б) Текущият символ не е първи, не е разделител, а предният е разделител.
	if (str[0] != '\0' && !isSeparator(str[0])) {
		count++; // а
	}
	for (int i = 1; str[i] != '\0'; i++) {
		if (!isSeparator(str[i]) && isSeparator(str[i - 1])) {
			count++; // б
		}
	}
	return count;
}

int main() {
	char buf[64];
	std::cin.getline(buf, 64);
	std::cout << "The entered string contains " << wordsCount(buf) << " words\n";
}