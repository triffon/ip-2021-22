#include <iostream>
const int MAX_SIZE = 128;
const int MAX_LETTERS = 26;

void initArray(char* arr, int size)
{
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

void printHisto(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
	}
}

void createHisto(char* arr, int* histo, int sizeOfCharArr)
{
	for (int i = 0; i < MAX_LETTERS; i++) {
		int curr = 0;
		for (int j = 0; j < sizeOfCharArr; j++) {
			if (arr[j] == 97 + i) {
				curr++;
			}
		}
		histo[i] = curr;
	}
}

int main() {
	char arr[MAX_SIZE];
	int histogram[MAX_LETTERS]; //26 letters

	int n;
	std::cin >> n;
	initArray(arr, n);

	for (int i = 0; i < MAX_LETTERS; i++) {
		histogram[i] = 0;
	}
	
	createHisto(arr, histogram, n);

	printHisto(histogram, MAX_LETTERS);

	return 0;
}