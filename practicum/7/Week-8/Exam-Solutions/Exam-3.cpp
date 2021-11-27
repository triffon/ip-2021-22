#include <iostream>

/*Задача 3. (1,5 т.) “Подредица” на дадена редица наричаме редица, която се получава след евентуалното изтриване на нула или повече елементи в началото и края на първоначалната редица.

Пример: редиците abc, cd, de са три подредици на редицата abcde.


“Ротация” на дадена редица се нарича такава подредба на елементите на редицата, която се получава като няколко елементи от края на редицата се преместят в същия ред в началото на редицата.

Пример: всички възможни ротации на редицата abcde са eabcd, deabc, cdeab и bcdea.


Да се напише програма, която въвежда от стандартния вход две положителни цели числа size1 и size2 и две редици от латински букви firstArr и secondArr, съответно с дължини size1 и size2. Програмата да определи дали някоя ротация на secondArr е подредица на firstArr, и ако това е така да изведе ротацията и да изведе колко символа от началото и края на firstArr трябва да се изтрият, за да се получи подредицата secondArr. Ако такава ротация няма, да се изведе подходящо съобщение.


Ограничения:

0 < size2 <= size1 < 1024*/

void rightRotationByOne(char arr[], int size)
{
	char lastElem = arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[0] = lastElem;
}

bool isSubArray(char A[], char B[], int size1, int size2)
{
	int firstArrTraversal = 0, secondArrTraversal = 0;
	while (firstArrTraversal < size1 && secondArrTraversal < size2) //obikalqme dvata masiva ednovremeno
	{
		if (A[firstArrTraversal] == B[secondArrTraversal]) // ako sa ravni produljavame
		{
			firstArrTraversal++;
			secondArrTraversal++;

			if (secondArrTraversal == size2) {  //ako vtoriq traversal e stignal do kraq na vtoriq masiv
				return true;
			}
		}
		else {
			firstArrTraversal = firstArrTraversal - secondArrTraversal + 1;
			secondArrTraversal = 0;
		}
	}
	return false;
}

void input(char arr[], unsigned size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void print(char arr[], unsigned size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}
}

int main()
{
	unsigned size1, size2;
	char firstArr[1024], secondArr[1024];
	std::cout << "Size 1: ";
	std::cin >> size1;
	std::cout << "Size 2: ";
	std::cin >> size2;
	input(firstArr, size1);
	input(secondArr, size2);
	if (size2 > size1) {
		std::cout << "Size2 cant be bigger than size1\n";
	}
	else {
		bool found = 0;
		for (int i = 0; i < size2; i++)
		{
			if (isSubArray(firstArr, secondArr, size1, size2)) {
				found = 1;
				break;
			}
			rightRotationByOne(secondArr, size2);
		}
		if (found) {
			std::cout << "Rotation found:\n";
			print(secondArr, size2);
		}
		else {
			std::cout << "No rotation found\n";
		}
	}

	return 0;
}