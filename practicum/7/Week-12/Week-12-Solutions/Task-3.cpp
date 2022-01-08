#include <iostream>

double calculate(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return calculate(n - 1) + 1.0 / (n * n);
}


int main() 
{

	return 0;
}