#include<iostream>

//task 1
int max_num(int a, int b) {
    if (a > b)
        return a;

    return b;
}

int main() {

    std::cout << "The max of (-3, 1) is " << max_num(-3, 1) << std::endl;
    std::cout << "------\n";

	return 0;
}