# Ex04 - Arrays

An array is an aggregate data type that lets us access many variables of the same type through a single identifier.

## NB

Beyond this course, arrays should be treated as just a building block for actual usable containers (e.g. vector).

## Declaration / Initialization

```c++
// Declaration
int declared[5]; // allocate 5 integers in conecutive places in memory

// Initialization
int initialized[5]{ 1, 2, 3, 4, 5 }; // Initialize the 5 integers with the values from the initializer list
// initialized -> [1, 2, 3, 4, 5]

// The initializer list could be smaller than the array, in this case the remaining elements are default initialized
int initialized2[5]{1, 2, 3};
// initialized2 -> [1, 2, 3, 0, 0]

// The initializer list cannot be larger than the array
int error[5]{ 1, 2, 3, 4, 5, 6}; // ERROR
```

## Size

- Must be known at compile time

```c++
int arr[5]; // GOOD, literal

const int size{5};
int arr[size]; // GOOD, const variable

int size_err{};
std::cin >> size_err;
int arr[size_err]; // ERROR
```

- Can be deduced from the initializer list

```c++
int arr[]{1, 2, 3}; // Allocates space for 3 integers
```

- Can be checked using the sizeof operator

```c++
int arr[10];
std::cout << sizeof(arr); // 10 * sizeof(int)
```

## Subscription

- Indexing starts at 0
- Operator[](size_t index)

```c++
int arr[]{1, 2, 3};
// Can be used to select an element
std::cout << arr[0]; // Prints: 1
// Can be used to mutate an element
arr[0] = 20;
std::cout << arr[0]; // Prints: 20
```

- Accessing or mutating elements outside of the array is an undefined behaviour

```c++
int arr[]{1, 2, 3};
std::cout << arr[3]; // UB, literally anyhting can happen
arr[3] = 10; // ^
```

## Arrays and functions

- Functions cannot return arrays
- Passing an array to function decays it to a pointer (more on those later)

```c++
size_t test(int arr[])
{
    return sizeof(arr);
}

int main()
{
    int arr[10];
    std::cout << sizeof(arr) << ' ' << test(arr);
}

//  warning: sizeof on array function parameter will return size of 'int *' instead of 'int []' [-Wsizeof-array-argument]
// Example output: 40 8
// 40 = 10 ints, 4 bytes each
// 8 = one 8 byte pointer
```

## BONUS: Iterating arrays

- Standard way using for-loop

```c++
int arr[]{1, 2, 3};
for (unsigned i = 0; i < 3; ++i)
{
    std::cout << arr[i] << 
}
// (-) We have to specify the start, the end (we need to know the size), how to progress and how to access specific elements
// (-) Doesn't work for every container
// (+) Flexible, we can change the above at will
```

- More readable way - range based loop

```c++
int arr[]{1, 2, 3};
for (int element : arr)
{
    std::cout << element;
}

// (+) Requires 0 knowledge about the container
// (+) More readable
// (-) Not flexible

// We need to use references (more on that later) to mutate it
int arr[]{1, 2, 3};
for (int& element : arr)
{
    element *= 2;
}
```

- Use prewritten algorithms (e.g. std::algorithm)
