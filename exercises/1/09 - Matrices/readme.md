# 08 - Matrices

```c++
const unsigned max_size{100};
```

## 01 - Print

```c++
void print(const int arr[max_size][max_size], unsigned rows, unsigned columns)
```

Given a matrix and its dimensions, print it on the console. Every row should be on a new line.

### Example

```c++
const int arr[][max_size]{
    {1, 2},
    {3, 4},
    {5, 6}
};

print(arr, 3, 2);

/*
1 2
3 4
5 6
*/
```

## 02 - Transpose

```c++
void transpose(const int arr[max_size][max_size], unsigned rows, unsigned columns, int arr_t[max_size][max_size])
```

Given a matrix, its dimensions and another matrix, copy the transposed first matrix into the second

### Example

```c++
const int arr[][max_size]{
    {1, 2},
    {3, 4},
    {5, 6}
};

int arr_t[max_size][max_size]{};
transpose(arr, 3, 2, arr_t);
print(arr_t, 2, 3);

/*
1 3 5
2 4 6
*/
```

## 03 - Min Elements

```c++
unsigned min_elements(const int arr[max_size][max_size], unsigned rows, unsigned columns, int output_begin[], unsigned first)
```

Given a matrix, its dimensions and a beginning of a range, copy the smallest number from every row in the matrix into the array.

### Example

```c++
const int arr[][max_size]{
    {1, 2},
    {3, 2},
    {5, 3}
};
int min_elems[max_size]{};
unsigned min_elems_end{min_elements(arr, 3, 2, min_elems, 0)};
 // -> 1 2 3
```

## 04 - Add

```c++
void add(const int a[max_size][max_size], const int b[max_size][max_size], unsigned rows, unsigned columns,
         int res[max_size][max_size])
```

Given 2 matrices with the same dimensions, copy their sum into a third one.

### Example

```c++
const int a[][max_size]{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

const int b[][max_size]{
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};

int res[max_size][max_size]{};

add(a, b, 3, 3, res);

print(res, 3, 3);

/*
10 10 10
10 10 10
10 10 10
*/
```

## 05 - Multiply

```c++
void multiply(const int a[max_size][max_size], unsigned a_rows, unsigned a_columns,
              const int b[max_size][max_size],
              int res[max_size][max_size])
```

Multiply 2 matrices, copy the result into a third one.

### Example

```c++
const int am[][max_size]{
    {1, 2, 3},
    {4, 5, 6},
};

const int bm[][max_size]{
    {7, 8},
    {9, 10},
    {11, 12}
};

int resm[max_size][max_size]{};

multiply(am, 2, 3, bm, resm);

print(resm, 2, 2);

/*
58 64
139 154
*/
```

## 06 - Spiral

```c++
unsigned spiral(const int arr[max_size][max_size], unsigned size, int output[], unsigned first)
```

Given a square matrix, copy all of its elements into the given range following a spiral pattern.

### Example

```c++
const int sp4[][max_size]{
    { 1,  2,  3,  4},
    {12, 13, 14,  5},
    {11, 16, 15,  6},
    {10,  9,  8,  7},
};

int spiral_arr4[16]{};

spiral(sp4, 4, spiral_arr4, 0);

for (int num : spiral_arr4)
{
    std::cout << num << ' ';
}

/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/
```