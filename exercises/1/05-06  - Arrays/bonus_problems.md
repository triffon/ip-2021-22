# 04 - Arrays

## Definitions for the exercise

- Range - array and 2 indexes denoting the begining end the end
- Sorted Range / array - A range / array where the elements are in increasing order

## 01

```c++
bool two_with_given_sum(const int arr[], unsigned begin, unsigned end, int sum);
```

Given a **sorted** range and a number, check whether there are 2 numbers in the range that add up to the given number.

Try to make a **single** pass through the array.

### Example

```c++
int arr[]{1, 2, 3, 4};

two_with_given_sum(arr, 0, 4, 6); // -> true (2 and 4)
two_with_given_sum(arr, 0, 4, 2); // -> false
```

### BONUS

```c++
bool three_with_given_sum(const int arr[], unsigned begin, unsigned end, int sum);
```

Same as above but for 3 numbers. Try to limit the number of iterations.

### Hint

Use the first function in the second one.

## 02 - Partition

```c++
unsigned partition(int arr[], unsigned begin, unsigned end, int pivot);
```

Given a range and a number, reorder the range so that every element smaller than or equal to the pivot is before every element bigger than it.

Return the new index of the first element bigger than the pivot.

### Example

```c++
int arr[]{4, 0, 2, 1, 5};
partition(arr, 0, 5, 3);

print(arr, 0, 5); // -> 0 2 1 4 5
// The exact order is not important
```

## 03 - Count Sort

```c++
void count_sort(int arr[], unsigned begin, unsigned end);
```

Given a range that only contains integers in the interval [0, 100), sort the range using the following method:
- Count the occurences of every number in that interval
- Copy the same amount of each number into the array in the correct order

### Example

```c++
int arr[]{1, 0, 2, 2, 1};
count_sort(arr, 0, 5);

print(arr, 0, 5); // -> 0 1 1 2 2
// Count 1 zero, 2 ones, 2 twos ...
// Then write them into the array
```

## 04 - Sieve of Eratosthenes

```c++
unsigned sieve_10000(int arr[], unsigned begin);
```

Generate every prime number less than 10000 using the sieve of eratosthenes method and copy it into the given range. Return the logical end of the new range.

### Example

```c++
int primes[10000]{};

unsigned end{sieve_10000(primes, 0)};
print(primes, 0, end); // -> 2 3 5 ...
```

## 05 - Lower Bound

```c++
unsigned lower_bound(const int arr[], unsigned begin, unsigned end, int element);
```

Return the index of the first element in a **sorted** range that is **not** less than the given element.

### Example

```c++
int arr[]{1, 2, 3, 5, 6};

lower_bound(arr, 0, 5, 4); // -> 3 (5 is NOT less than 4)
```

### Bonus

Reimplement binary_search from class using lower_bound instead of upper_bound.

## 06 - is_set

Let's define a **set** as a **sorted** range with no repeating elements.

```c++
bool is_set(const int arr[], unsigned begin, unsigned end);
```

Check if a given range is a **set**.

### Example

```c++
int set[]{1, 2, 3};
int not_set1[]{1, 2, 2};
int not_set2[]{1, 2, 1};

is_set(set, 0, 3); // -> true
is_set(not_set1, 0, 3); // -> false (has two 2s)
is_set(not_set2, 0, 3); // -> false (not )
```

## 07 - Unique

```c++
unsigned unique(int arr[], unsigned begin, unsigned end);
```

Given a **sorted** range and its size, remove all but the first element from every consecutive group of equivalent elements from the array and return the index of the new logical end.

### Example

```c++
int arr[]{0, 1, 1, 2, 2, 2, 3};
unsigned end{unique(arr, 0, 7)};

print(arr, 0, end); // -> 0 1 2 3
```

## 08 - Inclusion

```c++
bool includes(const int set_1[], unsigned begin_1, unsigned end_1,
              const int set_2[], unsigned begin_2, unsigned end_2)
```

Given 2 sets, check if the second is a subset of the first.

### Example

```c++
int set_1[]{1, 2, 3, 5};
int set_2[]{1, 2, 3};
int set_3[]{1, 2, 4};

includes(set_1, 0, 4,
         set_2, 0, 3); // -> true

includes(set_1, 0, 4,
         set_3, 0, 3); // -> false
```

## 09 - Set Difference

### HINT: FOR THE SET OPERATIONS MIMIC THE MERGE ALGORITHM

```c++
unsigned set_difference(const int input_1[], unsigned begin_1, unsigned end_1,
                        const int input_2[], unsigned begin_2, unsigned end_2,
                        int output[], unsigned output_begin);
```

Given 2 sets, copy their difference (input1 - input2) in a third one and return its end.

### Example

```c++
int set_1[]{1, 2, 3, 4};
int set_2[]{2, 4};
int result[10]{};

unsigned end{set_difference(set_1, 0, 4,
                            set_2, 0, 2,
                            result, 0)};

print(result, 0, end); // -> 1 3
```

## 10 - Set Intersection

Same as above but intersection ...

### Example

```c++
int set_1[]{1, 2, 3, 4};
int set_2[]{2, 4};
int result[10]{};

unsigned end{set_intersection(set_1, 0, 4,
                              set_2, 0, 2,
                              result, 0)};

print(result, 0, end); // -> 2 4
```

## 11 - Set Symmetric Difference ...

You know the drill.

```c++
int set_1[]{1, 2, 3, 4};
int set_2[]{2, 4, 5};
int result[10]{};

unsigned end{set_symmetric_difference(set_1, 0, 4,
                                      set_2, 0, 3,
                                      result, 0)};

print(result, 0, end); // -> 1 3 5
```

## 12 - Set Union

Hazard a guess

```c++
int set_1[]{1, 2, 3, 4};
int set_2[]{2, 4, 5};
int result[10]{};

unsigned end{set_union(set_1, 0, 4,
                       set_2, 0, 3,
                       result, 0)};

print(result, 0, end); // -> 1 2 3 4 5
```
