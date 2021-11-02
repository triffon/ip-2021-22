//Да се напише програма, която по въведени числа n и k(k > 0, k <= броя на цифрите на n) извежда на екрана k - тата цифра на n:
//-отдясно наляво
//-отляво надясно

#include<iostream>

int main() {
	int n, k;
	std::cin >> n >> k;

	int reverse = 0;
	int ctr = 0; //ще броим до коя цифра сме започнали

	//отдясно наляво
	while (n) {
		ctr++;

		if (ctr == k)
			std::cout << n % 10;


		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	std::cout << std::endl;

	ctr = 0;//ще броим наново

	//отляво надясно
	while (reverse) {
		ctr++;

		if (ctr == k) {
			std::cout << reverse % 10 << " ";
			break;
		}

		reverse /= 10;
	}

	std::cout << std::endl;

	return 0;
}