#include<iostream>

int main() 
{
	int arr[20][20];
	int sums[20]{};
	int n, m;
	std::cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cin >> arr[i][j];
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			sums[i] += arr[j][i];
		}
	}

	int maxIndex = 0;

	for (size_t i = 1; i < m; i++)
	{
		if (sums[i] > sums[maxIndex])
		{
			maxIndex = i;
		}
	}

	std::cout << maxIndex << std::endl;

	return 0;
}