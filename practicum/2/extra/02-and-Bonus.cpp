#include <iostream>

bool isSubNumber(int bigger, int smaller);

bool solve(int number1, int number2) // wrapper function
{
	if (number1 == 0 || number2 == 0)
		return true;


	if (number1 > number2)
		return isSubNumber(number1, number2);
	
	return isSubNumber(number2, number1);
}

bool isSubNumber(int bigger, int smaller)
{
	if (bigger == smaller || smaller == 0)
		return true;

	if (bigger == 0)
		return false;

	int biggerDigit = bigger % 10;
	int smallerDigit = smaller % 10;

	if (biggerDigit == smallerDigit)
		return isSubNumber(bigger / 10, smaller / 10);

	return isSubNumber(bigger / 10, smaller);
}




void deleteMatrix(float**& mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] mat[i];
	}

	delete[] mat;
	mat = nullptr;
}

void printEquation(const float* equation)
{
	std::cout << equation[0] << "x^2 + " << equation[1] << "x + " << equation[2] << '\n';
}


int main()
{
	int eqCount;
	const int eqSize = 3;
	const float epsilon = 0.001;

	std::cin >> eqCount;

	float** matrix = new (std::nothrow) float*[eqCount];
	if (!matrix)
	{
		std::cout << "Not enough memory!\n";
		return 1;
	}

	for (int i = 0; i < eqCount; i++)
	{
		matrix[i] = new (std::nothrow) float[eqSize];
		if (!matrix[i])
		{
			deleteMatrix(matrix, i);
			std::cout << "Not enough memory!\n";
			return 1;
		}
	}

	for (int i = 0; i < eqCount; i++)
	{
		std::cin >> matrix[i][0];
		std::cin >> matrix[i][1];
		std::cin >> matrix[i][2];
	}

	int rootsCount;

	std::cin >> rootsCount;

	float* roots = new (std::nothrow) float[rootsCount];
	if (!roots)
	{
		deleteMatrix(matrix, eqCount);
		std::cout << "Not enough memory!\n";
		return 1;
	}

	for (int i = 0; i < rootsCount; i++)
		std::cin >> roots[i];

	for (int i = 0; i < eqCount; i++)
	{
		for (int j = 0; j < rootsCount; j++)
		{
			if (abs(matrix[i][0] * roots[j] * roots[j] + matrix[i][1] * roots[j] + matrix[i][2]) <= epsilon)
			{
				printEquation(matrix[i]);
				break;
			}
		}
	}


	deleteMatrix(matrix, eqCount);
	delete[] roots;

	return 0;
}