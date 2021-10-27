# Ex03 - Loops

# Ex03 - Loops

Repeatedly execute a series of statements until a given condition is false

- for
- while
- do while
- range based for (next time)

## for

```c++
for (init; condition; step)
{
    statement();
}
```

### Evaluation

- init is evaluated only once at the start. Typically initializes loop variables
- condition is evaluated before every iteration. If condition is true -> statement is executed otherwise the loop terminates immediately
- step is evaluated after every iteration. Typicaly changes the loop variable

### Example

```c++
for (int i = 0; i < 10; i++)
{
    std::cout << i << '\n';
}

// Prints the numbers from 0 to 9.
```

- You can skip the initialization if you don't need a specialized loop variable

```c++
void print_digits(int number)
{
    for (; number; number /= 10)
    {
        std::cout << number % 10;
    }   
}

// Prints the digits of a number (in reversed order)

// Even if you don't need a specialized loop variable, you can state which one you are using

for (number; number; number /= 10) // GOOD, clearly state that the loop depends on number
{
    // ...
}
```

- You can skip the step in which case you probably shouldn't be using a for loop

## while

```c++
while(condition)
{
    statement();
}
```

### Evaluation

- Check if condition is true
- if yes -> execute statement and go to step 1
- otherwise -> terminate the loop immediately

### Example

```c++
int x{};
while(std::cin >> x)
{
    std::cout << x << '\n';
}

// Reads from the console and outputs the read number until the stream is closed (CTRL + Z/D/X/whatever it is on your OS)
```

## do while

```c++
do
{
    statement();
} while(condition);
```

### Evaluation

Same as while except you guarantee at least 1 iteration regardless of condition's value

## break

Immediately terminates the loop

```c++
int x{};
while(std::cin >> x)
{
    if (x == 2)
    {
        break;
    }

    std::cout << x << '\n';
}

// Reads from the console and outputs the read number until either 
// 1. the stream is closed (CTRL + Z/D/X/whatever it is on your OS)
// 2. the user inputs 2
```

## continue

Immediately go to the next iteration

```c++
for (int i = 0 ; i < 10; i++)
{
    if (i == 2)
    {
        continue;
    }

    std::cout << i << '\n';
}

// Print every number from 0 to 9 except 2 (for some reason)
```

## Nested loops

You can freely nest loops

```c++
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++) // Make sure loop variable names don't conflict
    {
        std::cout << i * j << ' ';
    }
    std::cout << '\n';
}

/*
Output:
0 0 0 
0 1 2 
0 2 4
*/
```

Loops don't need to be of the same type to be nested

```c++
for (int i = 0; i < 3; i++)
{
    int j{0};
    while(j < 3) // Make sure loop variable names don't conflict
    {
        std::cout << i * j << ' ';
        j++;
    }
    std::cout << '\n';
}

// Same output as above
```

## Infinite loops

Loops that will never terminate on their own. Avoid when possible.

### Using for

```c++
for (;;)
{
    // ...
}
```

### Using while

```c++
while (true)
{
    // ...
}
```

## Notes

- Prefer for to while when there is an obvious loop variable https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es72-prefer-a-for-statement-to-a-while-statement-when-there-is-an-obvious-loop-variable
- Prefer while to for when there isn't an obvious loop variable https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es73-prefer-a-while-statement-to-a-for-statement-when-there-is-no-obvious-loop-variable
- Minimize loop variables' scopes https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es74-prefer-to-declare-a-loop-variable-in-the-initializer-part-of-a-for-statement
- Avoid do while https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es75-avoid-do-statements
- Avoid break and continue when possible https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es77-minimize-the-use-of-break-and-continue-in-loops
- Only modify loop variables in the step part of for loops https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es86-avoid-modifying-loop-control-variables-inside-the-body-of-raw-for-loops

## Problems

### 01

Given an integer n, calculate n factorial

### 02

Given a double a, and a positive integer b, output a to the power of b (do not use std::pow)

#### Bonus 01
Make it work with negative powers

#### Bonus 02

Think of a way to significantly cut the number of iterations

### 03

Count number of digits in a number

### 04

Summ of digits in a number

### 05

Reverse a number

### 06

Check if a number is prime.

### 07

Given a non-negative number n, followed by n integers, return the number of primes among these integers.

### 08

Given a stream of numbers, output the current average after every given number (input numbers until we cancel the stream)

### 09

Output all prime factors of an integer

e.g. 24 -> 2 3

### 10

Output the nth fibonacci number

### 11

Calculate the GCD of 2 non-negative numbers

### 12

Given a non-negative number n, followed by n other numbers, check if the numbers form a

- strictly increasing sequence
- monotonic sequence

### 13

Given a non-negative integer n, followed by n other integers, find the length of the longest contiguous strictly increasing subsequence

### 14

Given a non-negative integer, output it as the product of prime factors

e.g. 24 -> 2 * 2 * 2 * 3

### 15

Given a non-negative integer n, followed by n other integers. Find the maxium possible sum of a contiguous subsequence

e.g.

Input
8
-2 -3 4 -1 -2 1 5 -3

Output
7

Explanation: 4 + (-1) + (-2) + 1 + 5 = 7.

Input
3
-1 -4 -10

Output
0

Explanation: All of the numbers are negative.

### 16

Given a positive integer and a number of iterations, approximate the square root of that integer using Newton's Method

### 17

Given a non-negative integer n, followed by n integers, one of which appears in the sequence more than the rest of the numbers combined (supermajority), find that number.

E.g.

Input
5
1 2 1 3 1

Output: 1

Explanation: There are 3 1s and 2 other numbers, so 1 is supermajority

Input
4
1 2 1 3

1 is majority, but not supermajority. This input is illegal and the program should assume that all inputs are legal.