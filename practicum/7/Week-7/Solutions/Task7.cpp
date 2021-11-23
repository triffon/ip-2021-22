#include<iostream>

//task 7
bool is_element_in(int arr[], int n, int element) {
	for (int i = 0; i < n; ++i)
		if (arr[i] == element)
			return true;

	return false;
}

int main() {

	int n = 5;
	int arr_yes[5] = { 1, 0, 3, 6, 2 };
	int arr_no[5] = { 1, 0, 3, 6, 1 };

	std::cout << (is_element_in(arr_yes, n, 2) ? "yes" : "no") 
		<< std::endl;

	std::cout << (is_element_in(arr_no, n, 2) ? "yes" : "no")
		<< std::endl;
	
	return 0;
}