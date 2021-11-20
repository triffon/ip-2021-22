# Array algorithms

- Follow the given signatures
- Try to reuse aglorithms when much as possible
- Ignore error checking
- We define range as an array and two indices that show the which elements in the array form that range
- One of these arguments is unneed but we will use it for now to avoid talking about pointers
- end and similar named variables point to the element after the last element in a range

## 01 - Print

```c++
void print(const int arr[], unsigned begin, unsigned end);
```
Print a given range

### Example

```c++
int arr[]{0, 1, 2, 3, 4};
print(arr, 1, 3); // -> 1 2
```

## 02 - Reverse

```c++
void reverse(int arr[], unsigned begin, unsigned end);
```

Given a range revese the elements inside of it

### Example

```c++
int arr[]{0, 1, 2, 3, 4};
reverse(arr, 1, 3);
print(arr, 0, 5); // -> 0 2 1 3 4
```

## 03 - Copy

```c++
unsigned copy(const int input_arr[], unsigned input_begin, unsigned input_end, 
              int output_arr[], unsigned output_begin);
```

Given one range and the beginning of another, copy the contents of the first one into the second.

Return the end of the second range.

### Example

```c++
int input[]{0, 1, 2, 3};
int output[10]{};

unsigned size{copy(input, 1, 3,
                   output, 0)};
print(output, 0, size); // -> 1 2
```

## 04 - Rotate

```c++
unsigned rotate(int arr[], unsigned begin, unsigned mid, unsigned end);
```

Given a range and a midpoint inside of it, swap the elements in the range such that [mid, end) goes to the start of the range and [first, mid) goes to the end.

Return the new index of the old first element.

### Example

```c++
int arr[]{0, 1, 2, 3, 4};
rotate(arr, 0, 2, 5);
print(arr, 0, 5); // -> 2 3 4 0 1
```

## 05 - Erase

```c++
unsigned erase(int arr[], unsigned size, unsigned index);
```

Given an array, its size and an index inside of it, delete the element on that index. Return the new size.

### Example

```c++
int arr[]{0, 1, 2, 3, 4};
unsigned new_size{erase(arr, 5, 2)};

print(arr, 0, new_size); // -> 0 1 3 4
```

## 06 - Insert

```c++
unsigned insert(int arr[], unsigned size, unsigned index, int element);
```

Given an array, its size, an index inside of it and a interger, insert the given integer on the given index. Return the new size.

### Example

```c++
int arr[6]{0, 1, 2, 3, 4};
unsigned new_size{insert(arr, 5, 2, 10)};

print(arr, 0, new_size); // -> 0 1 10 2 3 4
```

## 07 - Find

```c++
unsigned find(const int arr[], unsigned begin, unsigned end, int element);
```

Given a range and an integer, return the index of the first occurence of that integer or end if the range doesn't contain it.

### Example

```c++
int arr[]{0, 1, 2, 3, 4};

find(arr, 0, 5, 2); // -> 2
find(arr, 0, 2, 3); // -> 2 (3 is not in the range)
```

## 08 - Contains

```c++
bool contains(const int arr[], unsigned begin, unsigned end, int element);
```

Given a range and an integer, return whether the range contains the integer.

### Example

```c++
int arr[]{0, 1, 2, 3, 4};

contains(arr, 0, 5, 2); // -> true
contains(arr, 0, 2, 3); // -> false
```

## 09 - Inner Product

```c++
int inner_product(const int input_arr_1[], unsigned begin_1, unsigned end_1,
                  const int input_arr_2[], unsigned begin_2);
```

Given 2 ranges, return their inner product.

### Example

```c++
int a[]{0, 1, 2, 3, 4};
int b[]{5, 4, 2, 3, 1};

inner_product(a, 0, 5,
              b, 5); // -> 21
```

## 10 - Partial Sum

```c++
unsigned partial_sum(const int input_arr[], unsigned input_begin, unsigned input_end,
                     int output_arr[], unsigned output_begin);
```

Given a range and the beginning of a second one, write the partial sums of the first one into the second.

Return the end of the new range.

### Example

```c++
int arr[]{0, 1, 2, 3, 4};
int res[5]{};

unsigned size{partial_sum(arr, 0, 5,
                          res, 0)};

print(res, 0, size); // -> 0 1 3 6 10;
```

## 11 - Adjacent Difference

```c++
unsigned adjacent_difference(const int input_arr[], unsigned input_begin, unsigned input_end,
                     int output_arr[], unsigned output_begin);
```

Given a range and the beginning of a second one, write the differences between cosecutive elements in the first one into the second.

Return the end of the new range.

### Example

```c++
int arr[]{0, 1, 3, 6, 10};
int res[5]{};

unsigned size{adjacent_difference(arr, 0, 5,
                                  res, 0)};

print(res, 0, size); // -> 0 1 2 3 4;
```

## 12 - Min Index

```c++
unsigned min_element(const int arr[], unsigned begin, unsigned end);
```

Given a range find the index of the smallest element inside it.

### Example

```c++
int arr[]{1, 4, 3, 0, 2};
min_element(arr, 0, 5); // -> 3
```

## 13 - Selection Sort

```c++
void selection_sort(int arr[], unsigned begin, unsigned end);
```

Given a range, sort it using selection sort.

### Example

```c++
int arr[]{1, 4, 3, 0, 2};
selection_sort(arr, 0, 5);
print(arr, 0, 5); // -> 0 1 2 3 4
```

## 14 - Merge

```c++
unsigned merge(const int input_1[], unsigned begin_1, unsigned end_1,
               const int input_2[], unsigned begin_2, unsigned end_2,
               int output[], unsigned output_begin);
```

Merge 2 **sorted** ranges into a third **sorted** one.

Return the end of the third range.

### Example

```c++
int arr1[]{1, 3, 5};
int arr2[]{2, 6, 8};
int res[6]{};

unsigned size{merge(arr1, 0, 3,
                    arr2, 0, 3,
                    res, 0)};

print(res, 0, size); // -> 1 2 3 5 6 8
```

## 15 - Upper Bound

```c++
unsigned upper_bound(const int arr[], unsigned begin, unsigned end, int element);
```

Given a **sorted** range and an element, return the index of the first element in the range that is bigger than the given one (or end if there isn't one)

Try to use the binary search method to reduce comparisions.

### Example

```c++
int arr[]{0, 1, 2, 5};

upper_bound(arr, 0, 4, 4); // -> 3 (5 is bigger)
upper_bound(arr, 0, 4, 6); // -> 4 (no bigger element exists)
```

## 16 - Binary Search

```c++
bool binary_search(const int arr[], unsigned begin, unsigned end, int element);
```

Given a **sorted** range and an element, check whether the range contains the element.

### Example

```c++
int arr[]{0, 1, 2, 5};

binary_search(arr, 0, 4, 5); // -> true
binary_search(arr, 0, 4, 3); // -> false
```

## 17 - Insertion Sort

```c++
void insertion_sort(int arr[], unsigned begin, unsigned end);
```

Given a range, sort it using insertion sort.

## Example

```c++
// Same as selection sort ...
```
