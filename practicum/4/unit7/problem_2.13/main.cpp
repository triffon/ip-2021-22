#include <iostream>

bool isLowercaseLetter(char c) {
	return c >= 'a' && c <= 'z';
}

bool isAlphaNumeric(char c) {
	return c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || isLowercaseLetter(c);
}

// [a-zA-Z0-9]+@{1}[a-z]+.{com,bg}
// Част 0 - 1 или повече alphanumeric символа
// Част 1- @
// Част 2 - 1 или повече малки латински букви
// Част 3 - .
// Част 4 - низовете com/bg
bool isCorrectEmail(const char str[]) {
	int dotPosition = -1;
	bool atAppeared = false; // Дали символът '@' е вече срещнат

	// Итерираме, докато не срещнем символа '.'
	for (int i = 0;; i++) {
		if (str[i] == '\0') return false; // Ако низът свърши преди да намерим '.', значи не е валиден имейл адрес.
		if (str[i] == '.') {
			if (!atAppeared || str[i-1]=='@') return false; // Ако не е имало нито 1 буква между '@' и '.', значи не е валиден имейл адрес.
			dotPosition = i;
			break;
		}
		if (str[i] == '@') {
			// Ако срещаме '@' за втори път или не е имало букви преди '@', значи не е валиден имейл адрес.
			if (atAppeared || i==0) return false; 
			atAppeared = true;
			continue;
		}
		if (atAppeared) { // Тогава са позволени само малки латински букви
			if (!isLowercaseLetter(str[i])) {
				return false; // Ако има символ след @ различен от малка латинска буква и '.', значи не е валиден имейл адрес.
			}
		} else { // Тогава са позволени alphanumeric символи
			if (!isAlphaNumeric(str[i])) {
				return false; // Ако има символ преди @, който не е alphanumeric, значи не е валиден имейл адрес.
			}
		}
	}

	// На този етап всичко до dotPosition е коректно и dotPosition е индексът на '.' символа.
	// Остава да проверим дали остатъкът от низа е равен на "bg" или "com"
	bool isEqualToBg = str[dotPosition + 1] == 'b' && str[dotPosition + 2] == 'g' && str[dotPosition + 3] == '\0';
	bool isEqualToCom = str[dotPosition + 1] == 'c' && str[dotPosition + 2] == 'o' && str[dotPosition + 3] == 'm' && str[dotPosition + 4] == '\0';
	return isEqualToBg || isEqualToCom;
}


int main() {
	char str1[64];
	std::cin.getline(str1, 64);
	std::cout << std::boolalpha << isCorrectEmail(str1);
}
