/*
 * Задача 4
 * Създайте програма, която чете цяло четирицифрено число и проверява дали е симетрично. 
 * Например, 3003 е симетрично, но 1231 не е. Програмата трябва да валидира дали въведеното число има точно 4 цифри
 * и в противен случай да извежда съобщение за грешка и да прекратява изпълнението си.
 */
#include <iostream>
int main() {
	const int MIN_ALLOWED_NUMBER = 1000;
	const int MAX_ALLOWED_NUMBER = 9999;

	int x;
	std::cout << "Enter a four-digit number: ";
	std::cin >> x;

	if (x<MIN_ALLOWED_NUMBER || x>MAX_ALLOWED_NUMBER) {
		std::cout << "The number " << x << "does not have 4 digits";
		return 1; // Добра практика е при грешка в изпълнението програмите да завършват с код различен от 0.
	}

	const int firstDigit = x / 1000;
	const int secondDigit = x / 100 % 10;
	const int thirdDigit = x / 10 % 10;
	const int fourthDigit = x % 10;

	const bool isSymmetrical = firstDigit == fourthDigit && secondDigit == thirdDigit;

	if (isSymmetrical) {
		std::cout << "The number is symmetrical\n";
	}
	else {
		std::cout << "The number is not symmetrical\n";
	}

	// С тернарен оператор
	//std::cout << "The number is " << (isSymmetrical ? "symmetrical\n" : "not symmetrical\n");
	return 0;
}