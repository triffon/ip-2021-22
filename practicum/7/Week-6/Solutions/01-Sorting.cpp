#include<iostream>

const unsigned MAX_LEN = 1024;

void input_array(int arr[], int len) {
	for (unsigned i = 0; i < len; ++i)
		std::cin >> arr[i];
}

void print(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void sort(int arr[], int n) {
	int min_index = 0;

	for (int i = 0; i < n - 1; ++i) {
		min_index = i;

		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		if (min_index != i) {
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}

void shift(int arr[], unsigned& n, int pos) {
	for (int i = n; i > pos; --i)
		arr[i] = arr[i - 1];

	++n;
}

void insert_at(int arr[], int pos, int elem) {
	arr[pos] = elem;
}

int main() {
	//Input of arraays:
	//evens
	unsigned evens_len;
	std::cin >> evens_len;

	int evens[MAX_LEN];
	input_array(evens, evens_len);

	//odds
	unsigned odds_len;
	std::cin >> odds_len;

	int odds[MAX_LEN];
	input_array(odds, odds_len);

	//Sorting:
	//evens
	sort(evens, evens_len);
	print(evens, evens_len);

	//odds
	sort(odds, odds_len);
	print(odds, odds_len);

	//Insertion
	if (odds_len + evens_len > MAX_LEN)
		std::cout << "Cannot merge arrays!\n";

	int j = 0;
	for (int i = 0; i < evens_len; ++i) {
		while(j < odds_len) {
			std::cout << j << std::endl;

			if (evens[i] < odds[j]) {
				shift(odds, odds_len, j);
				print(odds, odds_len);

				insert_at(odds, j, evens[i]);
				break;
			}

			else if (evens[i] > odds[odds_len - 1]) {
				odds[odds_len] = evens[i];
				odds_len++;
			}
			j++;
		}
	}
	print(odds, odds_len);

	return 0;
}
