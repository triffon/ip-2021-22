#include <iostream>

int main()
{
	std::cout << "Please, enter three integer numbers!\n";

	int x;
	std::cout << "x = ";
	std::cin >> x;

	int y;
	std::cout << "y = ";
	std::cin >> y;

	int z;
	std::cout << "z = ";
	std::cin >> z;

	// дали има положително число?
	// трябва да конструираме булев израз

	bool atLeastOneIsPositive = (x > 0) || (y > 0) || (z > 0);
	std::cout << "At least one of the numbers is positive? " << atLeastOneIsPositive << '\n';

	// използваме аритметичната операция +, за да преброим положителните
	// всяко от условията се оценява като истина или лъжа, които участват като 1 и 0 в аритметичния израз 
	
	int countPositive = (x > 0) + (y > 0) + (z > 0);
	std::cout << "Exactly " << countPositive << " of the numbers is/are positive!\n";

	return 0;
}