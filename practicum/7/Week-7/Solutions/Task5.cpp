#include<iostream>

//� ��������, ������ �� ���������� ������ ��� ������� � ��
//�� ������ �������, � ����� �� ��������, 
//� ���� �� ���������� �������� ��������� �� ����
const unsigned MAX_ARRAY_LEN = 1024; 

//task 5
void input(int& n) { 
    //�������� �� ����������, ������ ������ ���������� �� n
    //�� �� ������� � ����� ��������� input
    std::cout << "Enter n: ";

    do {
        std::cin >> n;
    } while (n > MAX_ARRAY_LEN);
}

void input_array(int arr[], int n) {
    //int arr[] �� �� �������� � &, ������ ���� ������� ���������� 
    //�� � ����� �� ����� �����,� ���� ��� �������� ��, �.�.
    //���� ��� ����� �� ���������� � ��������� �������������� �� ��������
    std::cout << "Enter " << n << " numbers: ";

    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
}

void input_array_backwards(int arr[], int n) {
    std::cout << "Enter " << n << " numbers: ";

    while (n) { //��������� ���� � ���� �� �� ������� ����
        std::cin >> arr[n - 1];
        n--;
    }
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int n;
    input(n);

    int arr[MAX_ARRAY_LEN];
    input_array(arr, n);
    print_arr(arr, n);

    input_array_backwards(arr, n);
    print_arr(arr, n);

	return 0;
}