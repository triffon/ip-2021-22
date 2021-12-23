#include <iostream>
#include <cstring>
/*
	Създайте програма, която прочита дума с 8 или по-малко символа и квадратна матрица от символи.
	Изведете колко пъти матрицата съдържа думата:

	В редовете си (отляво-надясно или отдясно-наляво)
	В колоните си(в хоризонтална или вертикална посока)
	В главния и второстепенния си диагонал.
*/

const int MATRIX_SIZE = 64;
const int WORD_SIZE = 8;
void readMatrix(char matrix[][MATRIX_SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void printRowOccurences(char matrix[][MATRIX_SIZE], int matrixSize, char word[]) {
	const int wordLen = strlen(word);
	int leftToRight = 0;
	int rightToLeft = 0;
	for (int i = 0; i < matrixSize; i++) {
		int wordIdxLTR = 0; // LTR = left-to-right
		int wordIdxRTL = wordLen - 1; // RTL = right-to-left
		for (int j = 0; j < matrixSize; j++) {
			if (matrix[i][j] == word[wordIdxLTR]) {
				wordIdxLTR++;
				if (wordIdxLTR == wordLen) {
					leftToRight++;
					wordIdxLTR = 0;
				}
			}
			if (matrix[i][j] == word[wordIdxRTL]) {
				wordIdxRTL--;
				if (wordIdxRTL == -1) {
					rightToLeft++;
					wordIdxRTL = wordLen - 1;
				}
			}
		}
	}

	std::cout << "Left-to-right row occurences: " << leftToRight << '\n';
	std::cout << "Right-to-left row occurences: " << rightToLeft << '\n';

}

void printColOccurences(char matrix[][MATRIX_SIZE], int matrixSize, char word[]) {
	const int wordLen = strlen(word);
	int downwardOccurences = 0;
	int upwardOccurences = 0;
	for (int i = 0; i < matrixSize; i++) {
		int wordIdxDownward = 0;
		int wordIdxUpward = wordLen - 1;
		for (int j = 0; j < matrixSize; j++) {
			if (matrix[j][i] == word[wordIdxDownward]) {
				wordIdxDownward++;
				if (wordIdxDownward == wordLen) {
					downwardOccurences++;
					wordIdxDownward = 0;
				}
			}
			if (matrix[j][i] == word[wordIdxUpward]) {
				wordIdxUpward--;
				if (wordIdxUpward == -1) {
					upwardOccurences++;
					wordIdxUpward = wordLen - 1;
				}
			}
		}
	}

	std::cout << "Downward column occurences: " << downwardOccurences << '\n';
	std::cout << "Upward column occurences: " << upwardOccurences << '\n';
}

void printDiagOccurences(char matrix[][MATRIX_SIZE], int matrixSize, char word[]) {
	const int wordLen = strlen(word);
	int mainDiagOccurences = 0;
	int wordIdxLTR = 0;
	int wordIdxRTL = wordLen - 1;
	for (int i = 0; i < matrixSize; i++) {
		if (matrix[i][i] == word[wordIdxLTR]) {
			wordIdxLTR++;
			if (wordIdxLTR == wordLen) {
				mainDiagOccurences++;
				wordIdxLTR = 0;
			}
		}
		if (matrix[i][i] == word[wordIdxRTL]) {
			wordIdxRTL--;
			if (wordIdxRTL == -1) {
				mainDiagOccurences++;
				wordIdxRTL = wordLen - 1;
			}
		}
	}

	wordIdxLTR = 0;
	wordIdxRTL = wordLen - 1;

	int secDiagOccurences = 0;
	for (int i = 0; i < matrixSize; i++) {
		if (matrix[i][matrixSize-i-1] == word[wordIdxLTR]) {
			wordIdxLTR++;
			if (wordIdxLTR == wordLen) {
				secDiagOccurences++;
				wordIdxLTR = 0;
			}
		}
		if (matrix[i][matrixSize-i-1] == word[wordIdxRTL]) {
			wordIdxRTL--;
			if (wordIdxRTL == -1) {
				secDiagOccurences++;
				wordIdxRTL = wordLen-1;
			}
		}
	}

	std::cout << "Main diagonal occurences: " << mainDiagOccurences << '\n';
	std::cout << "Secondary diagonal occurences: " << secDiagOccurences << '\n';
}

int main() {
	char word[WORD_SIZE+1]; // 8 chars + '\0'
	std::cin.getline(word, WORD_SIZE+1);

	int matrixSize;
	std::cin >> matrixSize;
	char matrix[MATRIX_SIZE][MATRIX_SIZE];
	readMatrix(matrix, matrixSize);

	printRowOccurences(matrix, matrixSize, word);
	printColOccurences(matrix, matrixSize, word);
	printDiagOccurences(matrix, matrixSize, word);
}