#include<iostream>

//task 4
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {

    int a = 5, b = 8;
    std::cout << "After swapping a = " << a 
        << " with b = " << b << ", we get ";
    
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}