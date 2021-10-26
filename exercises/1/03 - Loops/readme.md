# Ex03 - Loops

## Notes

- switch (cont. from last time)
- for
- while
- do while
- break
- continue
- invariant

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