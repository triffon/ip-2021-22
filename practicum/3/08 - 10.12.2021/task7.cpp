#include<iostream>

int DotProduct(int first[20][20], int second[20][20], int row, int col, int m)
{
	int sum = 0;

	for (size_t i = 0; i < m; i++)
	{
		sum += first[row][i] * second[i][col];
	}

	return sum;
}

int main() 
{
	int arr[20][20];
	int n, m;
	std::cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cin >> arr[i][j];
		}
	}

	int arr2[20][20];
	int rows, cols;
	std::cin >> rows >> cols;

	if (m != rows)
	{
		std::cout << "Impossible multiplication" << std::endl;
		return 0;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> arr2[i][j];
		}
	}

	int result[20][20];

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			result[i][j] = DotProduct(arr, arr2, i, j, m);
		}
	}

	std::cout << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << result[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}