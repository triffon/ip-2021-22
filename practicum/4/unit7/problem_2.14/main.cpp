#include <iostream>

// Използваме unsigned char, защото прибавяйки голям offset към z например (ASCII код 122), можем да получим overflow.
char encryptLetter(unsigned char c, int offset) {
	const int alphabetSize = 'z' - 'a' + 1;
	if (c >= 'a' && c <= 'z') {
		c += offset;
		if (c > 'z') c -= alphabetSize;
	}
	if (c >= 'A' && c <= 'Z') {
		c += offset;
		if (c > 'Z') c -= alphabetSize;
	}
	return c;
}

char decryptLetter(unsigned char c, int offset) {
	const int alphabetSize = 'z' - 'a' + 1;
	if (c >= 'a' && c <= 'z') {
		c -= offset;
		if (c < 'a') {
			c += alphabetSize;
		}
	}
	if (c >= 'A' && c <= 'Z') {
		c -= offset;
		if (c < 'A') c += alphabetSize;
	}
	return c;
}


void encrypt(char str[], int offset, char encryptedStr[]) {
	for (int i = 0;; i++) {
		encryptedStr[i] = encryptLetter(str[i], offset);
		if (str[i] == '\0') break;
	}
}

void decrypt(char str[], int offset, char decryptedStr[]) {
	for (int i = 0;; i++) {
		decryptedStr[i] = decryptLetter(str[i], offset);
		if (str[i] == '\0') break;
	}
}


int main() {
	char input[64];
	char encryptedInput[64];
	char decryptedInput[64];

	int offset;

	std::cout << "Enter a string: ";
	std::cin.getline(input, 64);

	std::cout << "Enter a cipher offset: ";
	std::cin >> offset;

	encrypt(input, offset, encryptedInput);
	decrypt(encryptedInput, offset, decryptedInput);
	
	std::cout << "The encrypted string is " << encryptedInput << " and after decryption it is " << decryptedInput << '\n';
}