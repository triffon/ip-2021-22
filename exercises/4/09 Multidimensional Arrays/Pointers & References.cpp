#include <iostream>

// overloading the function...
// the functions should differ in the types or the number of the input parameters

// the argument is passed by reference
void increment(int& x)
{
	std::cout << "Address of X: " << &x << std::endl;
	++x;
}

// the argument is passed by pointer
void increment(int* x)
{
    std::cout << "Address in X: " << x << std::endl;
	++(*x);
}

int main()
{
    int var = 0;

    std::cout << "Address of the INT variable VAR: " << &var << std::endl;
    std::cout << "Size of the INT variable VAR: " << sizeof(var) << std::endl;
    std::cout << "Value of the variable VAR = " << var << std::endl;
    std::cout << std::endl;

    // How to define a pointer to a variable?
    // The type of the variable VAR is INT
    int* p_var = &var;
    std::cout << "Value of the pointer: " << p_var << std::endl;
    std::cout << "Address of the pointer: " << &p_var << std::endl;

    // How to use the pointer to modify the data in VAR?
    *p_var = 1;
    std::cout << "The new value of the variable VAR is " << var << std::endl;
    std::cout << "The variable value accessed using the pointer is " << *p_var << std::endl;
    std::cout << std::endl;

    // How to change the value of the pointer?
    // To link the pointer to another variable...
    int another_var = 2;

    // If the statement below is used, the value of the variable VAR will be changed...
    *p_var = another_var;
    std::cout << "Value of the pointer: " << p_var << std::endl;
    std::cout << "The new value of the variable VAR is " << var << std::endl;
    std::cout << std::endl;

    p_var = &another_var;
    std::cout << "Value of the pointer: " << p_var << std::endl;
    std::cout << "Address of the second variable is " << &another_var << std::endl;
    std::cout << std::endl;

    // when the argument is passed by reference
    std::cout << "OLD value of the second variable: " << another_var << std::endl;
    increment(another_var);
    std::cout << "NEW value of the second variable: " << another_var << std::endl;

    // when the argument is passed by pointer
    std::cout << "\nOLD value of the second variable: " << another_var << std::endl;
    increment(&another_var);
    std::cout << "NEW value of the second variable: " << another_var << std::endl;
    
    return 0;
}
