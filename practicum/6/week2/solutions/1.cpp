#include<iostream>

int main() {
	int n = 0;
	std::cin >> n;
	switch (n) {
	case 1: std::cout << "Jan"; break;
	case 2: std::cout << "Feb"; break;
	case 3: std::cout << "March"; break;
	case 4: std::cout << "April"; break;
	case 5: std::cout << "May"; break;
	case 6: std::cout << "June"; break;
	case 7: std::cout << "July"; break;
	case 8: std::cout << "Aug"; break;
	case 9: std::cout << "Sept"; break;
	case 10: std::cout << "Oct"; break;
	case 11: std::cout << "Nov"; break;
	case 12: std::cout << "Dec"; break;
	default:
		std::cout << "Invalid number";
		break;
	}
}
