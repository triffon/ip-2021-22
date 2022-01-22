#include <iostream>
#include <cmath>

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

const float EPSILON = 0.001;

bool isRoot(float root, const float* eq)
{
	return std::abs(eq[0] * root * root + eq[1] * root + eq[2]) <= EPSILON;
}

int main()
{
	const int EQ_SIZE = 3;

	int eqCount;
	std::cin >> eqCount;

	// create matrix for equations (array of equations)
	float** matrix = new (std::nothrow) float*[eqCount];
	if (!matrix)
	{
		std::cout << "Not enough memory!\n";
		return 1;
	}

	for (int i = 0; i < eqCount; i++)
	{
		matrix[i] = new (std::nothrow) float[EQ_SIZE];
		if (!matrix[i])
		{
			deleteMatrix(matrix, i);
			std::cout << "Not enough memory!\n";
			return 1;
		}
	}

	// input equations
	for (int i = 0; i < eqCount; i++)
	{
		std::cin >> matrix[i][0];
		std::cin >> matrix[i][1];
		std::cin >> matrix[i][2];
	}

	int rootsCount;
	std::cin >> rootsCount;

	// create array for roots
	float* roots = new (std::nothrow) float[rootsCount];
	if (!roots)
	{
		deleteMatrix(matrix, eqCount);
		std::cout << "Not enough memory!\n";
		return 1;
	}

	// input roots
	for (int i = 0; i < rootsCount; i++)
		std::cin >> roots[i];

	// search equations that satisfies a root
	for (int i = 0; i < eqCount; i++)
	{
		for (int j = 0; j < rootsCount; j++)
		{
			if (isRoot(roots[j], matrix[i]))
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
