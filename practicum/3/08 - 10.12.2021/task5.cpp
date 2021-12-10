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
	
	int topRowIndex = 0, rightColIndex = m - 1, bottomRowIndex = n - 1, leftColIndex = 0;

	//  0  1  2  3  4
	// 15 16 17 18  5
	// 14 23 24 19  6
	// 13 22 21 20  7
	// 12 11 10  9  8

	while (topRowIndex != bottomRowIndex && leftColIndex != rightColIndex)
	{
		for (size_t i = leftColIndex; i <= rightColIndex; i++)
		{
			std::cout << arr[topRowIndex][i] << " ";
		}
		topRowIndex++;

		for (size_t i = topRowIndex; i <= bottomRowIndex; i++)
		{
			std::cout << arr[i][rightColIndex] << " ";
		}
		rightColIndex--;

		for (int i = rightColIndex; i >= leftColIndex; i--)
		{
			std::cout << arr[bottomRowIndex][i] << " ";
		}
		bottomRowIndex--;

		for (int i = bottomRowIndex; i >= topRowIndex; i--)
		{
			std::cout << arr[i][leftColIndex] << " ";
		}
		leftColIndex++;
	}

	return 0;
}