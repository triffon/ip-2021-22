#include <iostream>


bool checkIfNumberIsCorrect(int matrix[][4], int row, int col)
{
	int number = matrix[row][col];

	bool checkLeft = true;
	if (col == 0)
	{
		checkLeft = number > 0;
	}
	else
	{
		checkLeft = number > matrix[row][col - 1];
	}
	bool checkRight = true;
	if (col == 3)
	{
		checkRight = number > 0;
	}
	else
	{
		checkRight = number > matrix[row][col + 1];
	}
	bool checkUp = true;
	if (row == 0)
	{
		checkUp = number > 0;
	}
	else
	{
		checkUp = number > matrix[row - 1][col];
	}
	bool checkDown = true;
	if (row == 3)
	{
		checkDown = number > 0;
	}
	else
	{
		checkDown = number > matrix[row + 1][col];
	}

	return (checkDown && checkLeft && checkRight && checkUp);
	 
}

int main() {

	//int matrix[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {20,14,15,16} };

	//int n = 4;

	//int row = 1;
	//int sum = 0;
	//for (int i = 1; i < n; i++)
	//{
	//	int col = 0;
	//	for (int j = row; j < n; j++)
	//	{
	//		if (checkIfNumberIsCorrect(matrix, j, col))
	//		{
	//			sum += matrix[j][col];
	//		}
	//		col++;
	//	}

	//	row++;
	//}
	//std::cout << sum;

	const char sentence[] = "cat,cat,ratsfgbstfb,big,cat,goat,dog,dog,dog";


	char* firstWord = nullptr, * secondWord = nullptr;

	int size = strlen(sentence);
	int index = 0;

	// gets first word
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (sentence[i] == ',')
		{
			int sizeOfWord = i - index;
			firstWord = new char[sizeOfWord + 1];
			for (int j = 0; j < sizeOfWord;j++)
			{
				firstWord[j] = sentence[index];
				index++;
			}
			firstWord[index] = '\0';
			index++;
			break;
		}
	}
	for (int i = index; sentence[i] != '\0';i++)
	{
		if (sentence[i] == ',' || i == size - 1)
		{
			if (i == size - 1) i++;
			int sizeOfWord = i - index;
			secondWord = new char[sizeOfWord + 1];
			for (int j = 0; j < sizeOfWord; j++)
			{
				secondWord[j] = sentence[index];
				index++;
			}
			secondWord[sizeOfWord] = '\0';
			index++;

			if (strcmp(firstWord, secondWord) == 0)  //-1, 0, 1
			{
				std::cout << firstWord << '\n';
				delete[] secondWord;
				if ((size - 1) == i)
				{
					delete[] firstWord;
				}
			}
			else
			{
				delete[] firstWord;
				if (!(size - 1 == i))
				{
					firstWord = new char[strlen(secondWord) + 1];
					strcpy_s(firstWord, strlen(secondWord) + 1, secondWord);
				}
				delete[] secondWord;
			}


		}
	}


	return 0;
}