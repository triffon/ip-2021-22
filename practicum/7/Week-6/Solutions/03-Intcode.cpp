#include<iostream>
const unsigned MAX_LEN = 1024;

int main() {
	//int n = 4;
	std::cin >> n;
	//Проверка дали n <= MAX_LEN

	//int arr[MAX_LEN] = { 1,0,3,5,2,9,8,5,99 }; // 1 0 3 5 2 792 8 5 99
	//int arr[MAX_LEN] = { 1,0,0,0,99 }; // 2 0 0 0 99
	//int arr[MAX_LEN] = { 2,3,0,3,99 }; // 2 3 0 6 99
	//int arr[MAX_LEN] = { 2,4,4,5,99,0 }; // 2 4 4 5 99 9801
	//int arr[MAX_LEN] = { 1,1,1,4,99,5,6,0,99 }; // 30 1 1 4 2 5 6 0 99

	//INVALID INPUTS:
	//int arr[MAX_LEN] = { 3, 1, 1, 5 };
	//int arr[MAX_LEN] = { 1, 2, 3, 8 };


	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	int res = 0;

	for (int i = 0; i < n; i += 4) {
		switch(arr[i]){
		case 1: 
			if (arr[i + 1] >= n || arr[i + 2] >= n || arr[i + 3] >= n) {
				std::cout << "BROKEN INPUT ARRAY!\n";
				i = n;
			}
			else {
				res = arr[arr[i + 1]] + arr[arr[i + 2]];
				arr[arr[i + 3]] = res;
			}
			break;

		case 2:
			if (arr[i + 1] >= n || arr[i + 2] >= n || arr[i + 3] >= n) {
				std::cout << "BROKEN INPUT ARRAY!\n";
				i = n;
			}
			else {
				res = arr[arr[i + 1]] * arr[arr[i + 2]];
				arr[arr[i + 3]] = res;
			}
			break;

		case 99:
			i = n;
			break;

		default:
			std::cout << "INVALID OP CODE!\n";
			i = n;
		}
	}

	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << ' ';

	return 0;
}