#include<iostream>

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//task11
void get_at_even_pos(int arr[], int n, int even_arr[], int& even_len) {

	even_len = 0;

	for (int i = 0; i < n; i += 2) {
		even_arr[even_len] = arr[i];
			++even_len;
	}
}

int main() {

	const unsigned MAX_ARRAY_LEN = 10;

	int arr[MAX_ARRAY_LEN] = { 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 };
	int n = 10;

	int evens[MAX_ARRAY_LEN];
	int evens_len = 0;

	get_at_even_pos(arr, n, evens, evens_len);
	
	print_arr(arr, n);
	std::cout << "has these elements at even positions: ";
	print_arr(evens, evens_len);

	return 0;
}