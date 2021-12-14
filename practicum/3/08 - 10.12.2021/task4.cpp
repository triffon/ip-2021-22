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
	
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m / 2; j++)
		{
			if (arr[i][j] != arr[i][m - j - 1])
			{
				std::cout << "Not a palindrome" << std::endl;
				return 0;
			}
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n / 2; j++)
		{
			if (arr[j][i] != arr[n - j - 1][i])
			{
				std::cout << "Not a palindrome" << std::endl;
				return 0;
			}
		}
	}
	
	std::cout << "Palindrome" << std::endl;

	return 0;
}