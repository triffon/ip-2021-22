#include <iostream>

const int xMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };;
const int yMoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

template <typename T>
void printTemplateMatrix(T** mat, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << mat[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

bool validPosition(int posX, int posY, int** solution, int solSize) {
	return (posX >= 0 && posY >= 0 && posX < solSize&& posY < solSize&& solution[posX][posY] == -1);
}

bool knightsWalkHelper(int** solution, int solSize, int currX, int currY, int posIndex) {
	if (posIndex == solSize * solSize) {
		return true;
	}
	int nextXPos, nextYPos;
	for (int i = 0; i < 8; i++) //for the 8 combs of moving the knight
	{
		nextXPos = currX + xMoves[i];
		nextYPos = currY + yMoves[i];
		if (validPosition(nextXPos, nextYPos, solution, solSize)) {
			solution[nextXPos][nextYPos] = posIndex;
			if (knightsWalkHelper(solution, solSize, nextXPos, nextYPos, posIndex++)) {
				return true;
			}
			else {
				solution[nextXPos][nextYPos] = -1;
			}
		}
	}
	return false;
}

bool knightsWalk(int** solution, int solSize) {


	solution[0][0] = 0;
	return knightsWalkHelper(solution, solSize, 0, 0, 1);
}

int main()
{
	int n;
	std::cin >> n; //n must be 8, but our backtracking algo is too greedy in time compexity context, its O(8 ^ (N^2))
	int** solution = new int* [n];
	for (int i = 0; i < n; i++)
	{
		solution[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			solution[i][j] = -1;
		}
	}


	if (knightsWalk(solution, n)) {
		printTemplateMatrix<int>(solution, n);
	}

	for (int i = 0; i < n; i++)
	{
		delete[] solution[i];
	}
	delete[] solution;

	return 0;
}