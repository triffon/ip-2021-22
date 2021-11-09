#include <iostream>

int main()
{
	/*Task 8. Едно число се нарича "силно" ако сумата на факториелите на неговите цифри е равна на самото число. 
	Например: 145 е "силно", защото `1! + 4! + 5! = 145`. Да се изпринтират на конзолата всички **силни** числа в интервала 
	`1 -> n` където `n` е въведено от конзолата.*/
	int n;
	std::cin >> n;
	int currentNumber, sum, fact, lastDigit;
	for (int i = 1; i <= n; i++)
	{
		currentNumber = i;
		sum = 0;

		while (currentNumber != 0) {	// find sum of factoriels of the digits
			fact = 1;
			lastDigit = currentNumber % 10;
			
			for (int j = 1; j <= lastDigit; j++) //find fact of currDigit
			{
				fact *= j;
			}
			sum += fact;
			currentNumber /= 10;
		}
		if (sum == i) std::cout << i << ' ';
	}

	return 0;
}