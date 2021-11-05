# More Problems

## 01

Given a positive integer, check if the sum of its even digits is equal to the sum of its odd digits

### Example

```c++
equal_sums(1223); // -> true
equal_sums(1234); // -> false
```

## 02

Given a positive integer n, output the first n numbers that statisfy the following predicates
- The difference between the smallest and the largest digit in the number is 3
- The sum of the digits of the number is prime

Then return the sum of these numbers

### Example
```c++
std::cout << sum_1(5) << "\n-------\n";
std::cout << sum_2(10) << '\n';

/* Output
14
25
30
36
41
146
-------
2
3
5
7
11
12
14
16
20
21
111
*/
```

## 04

Given a positive epsilon and a x, calculate the following sum

<img src="https://tex.s2cms.ru/svg/cos%5E3x%20%3D%20%5Cdfrac%7B1%7D%7B4%7D%5Csum_%7Bk%3D1%7D%5E%7B%5Cinfty%7D%20(-1)%5Ek%20%5Cdfrac%7B(3%5E%7B2k%7D%20%2B%203)%7D%7B(2k)!%7D%20*%20x%5E%7B2k%7D" alt="cos^3x = \dfrac{1}{4}\sum_{k=1}^{\infty} (-1)^k \dfrac{(3^{2k} + 3)}{(2k)!} * x^{2k}" />

The summation must stop after 2 consecutive members of the sequence with difference <= eps have been added. 

### Example

```c++
cos3(1, 0.001); // -0.842271  
```

## 05

Given a postivie integer n followed by the x and y coordinates of n points in a 2D plain, find the index of the point that is furthest away from the center (0, 0);

### Example

```c++
/*
Input:
1 3
2 2
3 2

Output -> 2 // point (3,2)
*/

furthest_point(3); // 2 (point (3, 2))
```


## 07

Given 2 positive integers p and q, check if the interval [p; q] contains a number where:

- The least significant digit is bigger than the 2nd least siginifant one
- The 2nd least significant digit is smaller than the 3rd least significant one
- The 3rd least significant digit is bigger than the 4th one
- ...

Example: 1324 -> 1 < 3 > 2 < 4

### Example

```c++
alternating_number_in_range(1300, 1400); // true -> 1301
alternating_number_in_range(1350, 1355); // false
```

## 08

Given 2 natural numbers p and k, Find the smallest natural number, bigger than p, that can be represented as the sum of the cubes of 2 natural numbers a and b where b = a + k;

### Example

```c++
find_smallest_cube_sum(100, 1); // 189
```

## 09

Given a positive integer, check if it contains duplicate digits

### Example

```c++
duplicate_digits(123); // false
duplicate_digits(1231); // true
```

## 10 

Given a positive integer n, return the sum of the first n positive integers who have a prime number of divisors smaller than n

### Example

```c++
// Input: 5
// Output: 23 (2 + 3 + 4 + 6 + 8)
```

## 12

Given n positive integers, return the largest one that is a power of 2 or 1 if there are none.

### Example

```c++
// input: 
// 4, 1, 3, 4, 16, 9, 9
largest_power_of_2(7); // -> 16
// input: 3, 6, 12, 5, 5
largest_power_of_2(5); // -> 1
```
