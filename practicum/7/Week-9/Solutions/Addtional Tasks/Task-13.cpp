#include <iostream>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swap1(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}


int main()
{
    //Test it
	return 0;
}