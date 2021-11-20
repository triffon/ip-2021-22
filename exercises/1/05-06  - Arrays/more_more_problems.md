## 01 - Equal

```c++
bool equal(const int arr_1, unsigned begin_1, unsigned end_1,
           const int arr_2, unsigned begin_2, unsigned end_2)
```

Given 2 ranges, check if they contain the same elements.

### Example

```c++
const int arr[]{1, 2, 1, 3};
const int arr2[]{1, 2};

std::cout << std::boolalpha << equal(arr, 0, 2, arr2, 0, 2); // -> true
std::cout << std::boolalpha << equal(arr, 1, 3, arr2, 0, 2); // -> false
```

## 02 - Search

```c++
unsigned search(const int arr[], unsigned begin, unsigned end,
                const int s_arr[], unsigned s_begin, unsigned s_end)
```

Given 2 ranges, find the beginning of the first occurence of the second range in the first. Return end if the second range is not a subsequence of the first.

### Example

```c++
const int arr[]{0, 1, 2, 1, 2};
const int seq[]{1, 2};
unsigned s_begin = search(arr, 0, 5, seq, 0, 2);
print(arr, s_begin, 5); // -> 1 2 1 2
```

## 03 - Search_n

```c++
unsigned search_n(const int arr[], unsigned begin, unsigned end, unsigned count, int elem)
```

Given a range, an element and a count, find the beginning of the first occurence of count consecutive copies of elem.

### Example

```c++
const int arr[]{0, 1, 1, 2, 1, 1, 1};
const int *s_begin = search_n(arr, 0, 6, 3, 1);
print(arr, s_begin, 6); // -> 1 1 1
```

## 04 - Adjacent Find

```c++
unsigned adjacent_find(cpnst int arr[], unsigned begin, unsigned end)
```

Given a range, find the first occurence of 2 consecutive, equal elements.

### Example

```c++
const int arr[]{0, 1, 2, 1, 1, 2, 2};
unsigned adj_begin = adjacent_find(arr, 0, 6);
print(arr, adj_begin, 6); // -> 1 1
```

## 05 - Find first of

```c++
unsigned find_first_of(const int arr[], unsigned begin, unsigned end,
                       const int s_arr[], unsigned s_begin, unsigned s_end)
```

Given 2 ranges, find the first occurence of ANY element from the second one in the first one.

### Example

```c++
const int arr[]{0, 1, 2, 3, 4};
const int seq[]{2, 4};

unsigned found = find_first_of(arr, 0, 5, seq, 0, 2);
std::cout << arr[found]; // -> 2
```

## 06 - Swap Ranges

```c++
void swap_ranges(int arr_1, unsigned begin_1, unsigned end_1,
                 int arr_2, unsigned begin_2)
```

Given 2 ranges, swap their contents

### Example

```c++
int arr1[]{1, 3, 5};
int arr2[]{2, 4, 6};

swap_ranges(arr1, 0, 3, arr2, 0);
print(arr1, 0, 2); // -> 2 4 6
print(arr2, 0, 2); // -> 1 3 5
```