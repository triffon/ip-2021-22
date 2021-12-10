#include<iostream>

double avarage(int arr[20][20], int k, int row, int col)
{
	double sum = 0;

	for (size_t i = row; i < row + k; i++)
	{
		for (size_t j = col; j < col + k; j++)
		{
			sum += arr[i][j];
		}
	}

	return sum / (k * k);
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

	int k;
	std::cin >> k;
	
	if (k > n || k > m) 
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	int maxRowIndex = 0, maxColIndex = 0;
	double maxAvg = avarage(arr, k, maxRowIndex, maxColIndex);

	for (size_t i = 0; i < n - k; i++)
	{
		for (size_t j = 0; j < m - k; j++)
		{
			double currAvg = avarage(arr, k, i, j);

			if (currAvg > maxAvg)
			{
				maxRowIndex = i;
				maxColIndex = j;
				maxAvg = currAvg;
			}
		}
	}

	for (size_t i = maxRowIndex; i < maxRowIndex + k; i++)
	{
		for (size_t j = maxColIndex; j < maxColIndex + k; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}