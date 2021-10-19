#include<iostream>

int main() {
	int first = 0, second = 0, third = 0;
	std::cin >> first >> second >> third;
	
	int max = 0, mid = 0, min = 0;

	if (first > second) {
		if (first > third) {
			max = first;

			if (second > third) {
				mid = second;
				min = third;
			}
			else {
				mid = third;
				max = second;
			}
		}
		else {
			mid = first;
			min = second;
			max = third;
		}
	}
	else if (second > third) {
		max = second;
		
		if (first > third) {
			mid = first;
			min = third;
		}
		else {
			mid = third;
			min = first;
		}
	}
	else {
		max = third;
		mid = second;
		min = first;
	}
	std::cout << max << " " << mid << " " << min;
}
