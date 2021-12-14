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

	for (size_t i = 0; i < n; i += 2)
	{
		for (size_t j = 0; j < n / 2; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][n - j - 1];
			arr[i][n - j - 1] = temp;
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}	

	return 0;
}