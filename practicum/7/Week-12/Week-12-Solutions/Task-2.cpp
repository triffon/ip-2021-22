#include <iostream>

double calculate(int y, double x)
{
    if (y == 2)
    {
        return x + 2;
    }

    return calculate(y - 1, x) * x + y;
}

int main()
{


	return 0;
}