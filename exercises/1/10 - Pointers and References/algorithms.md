# More algorithms

- Follow the given signatures
- Try to reuse aglorithms when much as possible
- Ignore error checking
- ~We define range as an array and two indices that show the which elements in the array form that range~
- ~One of these arguments is unneed but we will use it for now to avoid talking about pointers~
- We define range as a pair of pointers (beginning + end)
- *Write non-const versions of all the functions*
- end and similar named variables point to the element after the last element in a range
- Reuse old algorithms when possible

## 01 - Equal

```c++
bool equal(const int* begin_1, const int* end_1, const int* begin_2, const int* end_2)
```

Given 2 ranges, check if they contain the same elements.

### Example

```c++
const int arr[]{1, 2, 1, 3};
const int arr2[]{1, 2};

std::cout << std::boolalpha << equal(std::begin(arr), std::begin(arr) + 2, std::begin(arr2), std::end(arr2)); // -> true
std::cout << std::boolalpha << equal(std::begin(arr) + 2, std::end(arr), std::begin(arr2), std::end(arr2)); // -> false
```

## 02 - Search

```c++
const int* search(const int* begin, const int* end, const int* s_begin, const int* s_end)
```

Given 2 ranges, find the beginning of the first occurence of the second range in the first

### Example

```c++
const int arr[]{0, 1, 2, 1, 2};
const int seq[]{1, 2};
const int* s_begin = search(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
print(s_begin, std::end(arr)); // -> 1 2 1 2
```

## 03 - Search_n

```c++
const int* search_n(const int* begin, const int* end, unsigned count, int elem)
```

Given a range, an element and a count, find the beginning of the first occurence of count consecutive copies of elem.

### Example

```c++
const int arr[]{0, 1, 1, 2, 1, 1, 1};
const int *s_begin = search_n(std::begin(arr), std::end(arr), 3, 1);
print(s_begin, s_begin + 3); // -> 1 1 1
```

## 04 - Adjacent Find

```c++
const int* adjacent_find(const int* begin, const int* end)
```

Given a range, find the first occurence of 2 consecutive, equal elements

### Example

```c++
const int arr[]{0, 1, 2, 1, 1, 2, 2};
const int* adj_begin = adjacent_find(std::begin(arr), std::end(arr));
print(adj_begin, adj_begin + 2); // -> 1 1
```

## 05 - Find End

```c++
const int* find_end(const int* begin, const int* end, const int* s_begin, const int* s_end)
```

Given 2 ranges, find the beginning of the last occurence of the second range in the first

### Example

```c++
const int arr[]{0, 1, 2, 1, 2};
const int seq[]{1, 2};
const int* s_begin = find_end(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
print(s_begin, std::end(arr)); // -> 1 2
```

## 06 - Find first of

```c++
const int* find_first_of(const int* begin, const int* end, const int* s_begin, const int* s_end)
```

Given 2 ranges, find the first occurence of ANY element from the second one in the first one.

### Example

```c++
const int arr[]{0, 1, 2, 3, 4};
const int seq[]{2, 4};

const int* found = find_first_of(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
std::cout << *found; // -> 2
```

## 07 - Swap Ranges

```c++
void swap_ranges(int* begin_1, int* end_1, int* begin_2)
```

Given 2 ranges, swap their contents

### Example

```c++
int arr1[]{1, 3, 5};
int arr2[]{2, 4, 6};

swap_ranges(std::begin(arr1), std::end(arr1), std::begin(arr2));
print(std::begin(arr1), std::end(arr2)); // -> 2 4 6
print(std::begin(arr1), std::end(arr2)); // -> 1 3 5
```

## 08 - Copy Backward

```c++
int* copy_backward(const int* begin, const int* end, int* output_begin)
```

Given an input range and the begining of an output range, place all the elements from the first range into the second but backwards. Return the beginning of the second range.

### Example

```c++
const int arr[]{1, 2, 3};
int backward_copy[3]{};

copy_backward(std::begin(arr), std::end(arr), std::begin(backward_copy));
print(std::begin(backward_copy), std::end(backward_copy)); // -> 3 2 1
```

## 09 - Remove

```c++
int* remove(int* begin, int* end, int element)
```

Given a range and an element, remove all occurences of the element in the range and return the new logical end

### Example

```c++
int arr[]{0, 1, 2, 1, 4, 1, 6};
int* new_end = remove(std::begin(arr), std::end(arr), 1);
print(std::begin(arr), new_end); // -> 0 2 4 6
```

## 10 - Replace

```c++
void replace(int* begin, int* end, int old_value, int new_value)
```

Given a range and 2 values, replace all occurences of the old_value with the new_value

## Example

```c++
int arr[]{0, 9, 2, 9, 3, 9};
replace(std::begin(arr), std::end(arr), 9, 1);
print(std::begin(arr), std::end(arr)); // -> 0 1 2 1 3 1
```