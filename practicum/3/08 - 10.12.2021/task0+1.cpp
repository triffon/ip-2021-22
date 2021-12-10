#include<iostream>

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
	std::cout << std::endl;

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << arr[j][i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i][i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// (0, n-1) (1, n-2) (2, n-3) ... (i, n - i - 1)

	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i][n - i - 1] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// (X .. .. ..)
	// (.. X .. ..)
	// (.. .. X ..)
	// (.. .. .. X)

	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}