/*
 * Задача 10
 * Създайте програма, която чете 3 цели числа day, month и year. Програмата трябва да провери дали тези 3 числа формират валидна дата 
 * и ако това е така да изведе следващия ден във формата 13 January 2021.
 */
#include <iostream>

enum Month {
	JANUARY = 1, // В противен случай изброените стойности ще започват от 0.
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

int main() {
	int day, month, year;
	std::cin >> day >> month >> year;

	const bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	const int DAYS_IN_FEBRUARY = isLeapYear ? 29 : 28;

	int daysInCurrentMonth;
	if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) {
		daysInCurrentMonth = 30;
	}
	else if (month == FEBRUARY) {
		daysInCurrentMonth = DAYS_IN_FEBRUARY;
	}
	else {
		daysInCurrentMonth = 31;
	}

	const bool isValidDate = month >= JANUARY && month <= DECEMBER && day >= 1 && day <= daysInCurrentMonth;
	if (!isValidDate) {
		std::cout << "The entered date is not valid";
		return 1;
	}

	/*
	  На този етап, въведената дата е валидна. Има няколко различна варианта за следващия ден:
	    - Ако е 31 декември -> 1 January, <year+1>
		- Ако е последния ден на месец, различен от декември => 1, <month+1> <year>
		- В противен случай, следващия ден е <day+1> <month> <year>
	*/

	// Пренаписваме входните променливи с новите стойности за краткост.
	if (month == DECEMBER && day == 31) {
		day = 1;
		month = JANUARY;
		year++;
	}
	else if (day == daysInCurrentMonth) {
		day = 1;
		month++;
	}
	else {
		day++;
	}

	std::cout << "The next day is " << day << " ";
	switch (month) {
		case JANUARY: std::cout << "January "; break;
		case FEBRUARY: std::cout << "February "; break;
		case MARCH: std::cout << "March "; break;
		case APRIL: std::cout << "April "; break;
		case MAY: std::cout << "May "; break;
		case JUNE: std::cout << "June "; break;
		case JULY: std::cout << "July "; break;
		case AUGUST: std::cout << "August "; break;
		case SEPTEMBER: std::cout << "September "; break;
		case OCTOBER: std::cout << "October "; break;
		case NOVEMBER: std::cout << "November "; break;
		case DECEMBER: std::cout << "December "; break;
	}
	std::cout << year;

	return 0;
}