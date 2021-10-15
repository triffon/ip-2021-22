# Ex01 - Types, Operators and Pure Functions

## Hello World / General structure of a program

The most complicated beginner program ever

```c++
#include <iostream>
// Preprocessing directive #include, finds the given file and inserts its code
// iostream - (input, output stream) - standard library that we can use to write in / read from the console

// using namespace std; // Bad Practice. Pollutes the namespace with unused things

int main() // Every program starts from the main function
// int means that it returns an int value
// () means that it takes 0 arguments
{
    std::cout << "Hello World" << '\n';
    // std:: something that belongs to the std namespace
    // cout - (standard character output, console by default), a stream object that can be used to write on the console
    // << - binary operator for adding data TO a stream

    // std::endl -> (endline), outputs a new line and flushes the buffer
    // '\n' -> char literal, outputs a new line without flushing the buffer

    // "Hello World" - string literal

    return 0;
    // Return value of the funtion
    // 0 usually means successful execution
}

```

## Notes

- Do not include entire namespaces
```c++
using namespace std; // BAD

using std::cout; // GOOD
std::cout << "..."; // GOOD
```
- Add an empty line at the end of the file
- Avoid writing multiple statements on the same line
```c++
std::cout << "text"; return 0; // BAD

std::cout << "text";
return 0; // GOOD
```
- Use either spaces (usually 4) or tabs for identation but be consistent
```c++
int main()
{
    statement1();
     statement2(); // BAD, different number of spaces
	statement3(); // BAD, mixed tabs and spaces

    return 0;
}
```
- main should be int and not void
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f46-int-is-the-return-type-for-main


## Variables

### Definitions

- value: A piece of data, stored in memory
- object: region of storage (usually memory) that has a value and other associated properties
- variable: a named object
- identifier: name of a variable

#### Notes

- Names can contains letters, underscores and digits (but cannot start with a digit)
- Names starting with underscores should be avoided most of the times (mostly used in the standard library)
- Names should begin with a lower case letter
```c++
int snake_case_example;
int camelCaseExample;
```
- Be consistent
```c++
int snake_case_name;
int camelCaseName; // BAD, mixed styles

int snake_case_name;
int another_snake_case_name; // GOOD

int camelCaseName;
int anotherCamelCaseName; // GOOD
```
- Names should make sense and give information, don't rely on comments
```c++
// s is salary
int s1 = 3000; // BAD, you didn't have to use a comment for this

int s2 = 3000; // WORSE, you didn't even use a comment

int salary = 3000; // GOOD, name expresses intent
```

### Declaration vs Initialization

```c++
// Declaration
int a; // Creates a new int variable named a. The initial value is NOT 0

// Initialization
// copy initialization
int b = 10;
// direct initialization
int c(10); // Same as above for primitive types, can be faster for more complext types
// uniform intialization
int d{10}; // Not every type supports direct initialization

// zero initialization
int e{}; // e is the 0 of the type (e.g. 0 for ints 0.0 for doubles, '\0' for chars ...)
```

#### Notes
- Only make one definition per line
```c++
int a, b; // BAD

int a;
int b; // GOOD, easier to read, easier to change the type of only 1 variable, cannot lead to confusion with pointers (later exercise)
```
- Prefer uniform initialization
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md?fbclid=IwAR0QsjJ28rbBSLBmdqdZjayc67CODBHhEPHKCY3M_xHOOizl7qPnAUrYVGE#Res-list
- Always initialize variables upon creation
```c++
int a;
/* ... */
a = 10; // BAD, someone could use a before this line and break something

int a{10}; // GOOD, you cannot use a before this
```

## Basic Primitive Types

### int
- integer
- whole number
- Size is not specified in the standard but it is almost always 4 bytes
- You can check the size of a type using the sizeof operator
```c++
// BONUS:
std::cout << sizeof(int) << '\n'; // Should output 4 on your machine
```

### unsigned
- a non-negative integer
- size is usually the same as int

### double
- floating point number
- usually 8 bytes
- not very precise, do not compare using ==
```c++
double a{/*...*/};
double b{/*...*/};
a == b; // BAD

#include <cmath> // Needed for abs (absolute value), more on this in a later exercies
double eps = 0.001;
std::abs(a - b) < eps; // GOOD
```
https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/


### float
- same as double but 4 bytes => even less precision
- literals

### char
- always 1 byte
- contains a number between 0 and 255 that is mapped to a character using what's called an ASCII table
http://www.asciitable.com/
- literals
```c++
char a{'a'}; // one character in single quotes
char b{'\n'}; // special charactes are created using \
```

### bool
- always 1 byte
- either true or false (only 2 values so 7 wasted bits)
- 0 is false, every other value is true
- literals
```c++
bool a{true};
bool b{false};
```

### And more ...

## Operators

### Assignment Operator

- Assigns given value to a variable;

```c++
int f() { return 0; };

int main()
{
    int a{};
    int b{10};
    a = 10; // could assign a literal
    a = b; // or a variable
    a = f(); // or the result of a function

    return 0;
}

```
- Returns the variable we assigned to
```c++
int a{};
int b{};

a = b = 10;
// This is equivalent to: b = 10; a = b;
// Both a and b become 10
```

### Arithmetic Operators
```c++
// +, - and * are standard
int a{10};

int b{a + 10}; // b = 20; 
int c{a - 10}; // c = 0;
int d{a * 10}; // d = 100;

// For integers / is whole division and % is modulo

int e{a/3}; // e = 3
int f{a%3}; // f = 1
// a = 3 * e + f;

// For floats / is regular division

double g = a / 20.0; // g = 0.5

// all of these return a new number
```

### Shorthand Operators
```c++
int a{10};

a += 10; // equivalent to a = a + 10;
a -= 10; // equivalent to a = a - 10;
// ...

a++; // equivalent to a = a + 1; returns the old value
++a; // equivalent to the above but returns the new value

a--; // equivalent to a = a - 1; returns the old value
--a; // equivalent to the above but returns the new value
```

#### Notes
- For simple types the compiler will replace a++ with ++a when you don't need the return value
- For more complext types prefer ++a when possible
- Try to avoid using the return value of ++ and -- as it leads to confusion

### Comparasion Operators

Compare two values and return a bool.

```c++
int a{10};

// equality
bool cmp1{a == 10}; // !!! = is not ==; cmp1 = true

// The next 4 are the same as the math equivalents 
bool cmp2{a < 10}; // cmp2 = false
bool cmp3{a > 10}; // cmp3 = false
bool cmp4{a <= 10}; // cmp4 = true
bool cmp5{a >= 10}; // cmp5 = true

// inequality
bool cmp6{a != 10}; // cmp6 = false 
```
## Input & Output

This is actually a really hard topic that we will gloss over

### Reading data FROM the console

```c++
int a{};
std::cin >> a;

// cin -> standard character input stream object
// >> -> stream operator that takes data from a stream and puts it in an object
```

### Writing data TO the console
```c++
int a{20};
std::cout << a;

// cout -> standard character output stream object
// >> -> stream operator that takes an object and serializes it to a stream
```

### Notes

- Avoid flushing for no reason
```c++
std::cout << a << std::endl; // BAD, do we really need to flush here?
std::cout << a << '\n'; // GOOD, the compiler will print this when necessary
```
- Sometimes it is necessary
```c++
// Super simple and silly example

std::cout << "I am about to do something bad" << '\n';
something_terribly_misguided_that_crashes_the_program();

// There is no guarantee that the compiler will print the previous message before the program crashes

std::cout << "I am about to do something bad" << std::endl;
something_terribly_misguided_that_crashes_the_program();

// The message will be printed 100% before the crash
```
- BONUS: You can flush without adding a new line using std::flush
```c++
std::cout << "kappa123" << std::flush;
```

## Problems

### 01

Given the sides of a triangle calculate its
- perimeter
- semiperimeter
- area

## 02

Given a 3-digit number, calculate the sum of its digits

## 03

Given 2 3-digit numbers, check if the products of their digits is the same

## 04

Given a 3-digit number, calculate the reverse number (e.g. 123 -> 321)

## 05

Given a 3-digit number, check if it is a palindrome.

## 06

Given a positive integer and a divisor, retun the smallest integer, equal to or greater than the given one that is divisible by the divisor.

e.g.
10, 3 -> 12
12, 3 -> 12

## 07

Given 2 integers, find the smaller one.

## 08

Given a 3-digit number, calculate the sum of its odd digits.

## 09

Given a year, check if it is leap.

## 10

Given the 3 sides of a triangle, check if such triangle can exist