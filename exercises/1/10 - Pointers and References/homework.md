# Bonus Problems

### Iota

```c++
void iota(int * begin, int * end, int value)
```

Fill the range [begin; end) with sequentially with numbers starting with value and increasing by 1.

#### Example

```c++
int range[10]{};
iota(std::begin(range), std::end(range), 0);

for (int num : range)
{
    std::cout << num << ' ';
}

// 0 1 2 3 4 5 6 7 8 9
```

### Next permutation

```c++
bool next_permutation(int * begin, int * end)
```

Given a range, change it to the next possible (in lexicographical order) permutation of its elements. If the range is in the last possible permutation (sorted in decreasing order), reset it to the first one (sorted in increasing order) and return false. Otherwise return true.

```c++
int arr[]{1, 2, 3};

do
{
    for (int num : arr)
    {
        std::cout << num << ' ';
    }

    std::cout << std::endl;
} while(next_permutation(std::begin(arr), std::end(arr)));

/*
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
*/
```

## Randomized Algorithms

### Random Uniformly Distributed Numbers

#### Integers

```c++
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

std::cout << std::uniform_int_distribution<>(0, 10)(gen); // Generates a random integer from the interval [0; 10] following a uniform distribution
std::cout << std::uniform_int_distribution<unsigned>(0, 10)(gen); // Same as above but casts to unsigned
```

#### Real Numbers

```c++
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::cout << std::uniform_real_distribution<> dis(0, 1)(gen); // Generates random number from [0, 1)
```

### Shuffle

```c++
void shuffle(int * begin, int * end)
```

Randomly shuffle a given range. Every permutation should be equally likely.

#### Example

```c++
int arr[10]{};
iota(std::begin(arr), std::end(arr), 0);

shuffle(std::begin(arr), std::end(arr));

for (int num : arr)
{
    std::cout << num << ' ';
}

std::cout << '\n';

shuffle(std::begin(arr), std::end(arr));

for (int num : arr)
{
    std::cout << num << ' ';
}

/*
    2 6 0 9 8 4 1 5 7 3
    1 5 4 0 3 8 2 7 9 6
*/
```

### Sample

```c++
int * sample(const int * begin, const int * end, int * out, unsigned samples)
```

Implement Reservoir Sampling algorithm to randomly select 'samples' integers from given range and copy them to the second given range. If samples > size of the first range, copy the first range. Every element should have the same probability of being selected.

#### Example

```c++
int * samples_end{sample(std::begin(arr), std::end(arr), std::begin(samples), 3)};

for (int * i = std::begin(samples); i < samples_end; ++i)
{
    std::cout << *i << ' ';
}

std::cout << '\n';

samples_end = sample(std::begin(arr), std::end(arr), std::begin(samples), 3);

for (int * i = std::begin(samples); i < samples_end; ++i)
{
    std::cout << *i << ' ';
}

/*
    0 3 5
    7 4 8
*/
```

### Monte Carlo

```c++
double approximate_pi(unsigned attempts, double eps)
```

Approximate the value of PI using a Monte Carlo algorithm
 - Imagine you have a square with a lower left corner in (0, 0) and upper right in (1, 1)
 - Consider a circle with center (0.5, 0.5) and radius 0.5 inside it
 - Generate *attempts* number of points **inside** the square
 - Count the amount of points that are also inside the circle
 - The ratio between the points inside the circle and all points should be approximately PI / 4

#### Example

```c++
std::cout << approximate_pi(1000000, 0.0001) << '\n'
          << approximate_pi(1000000, 0.0001) << '\n';

/*
    3.14372
    3.14187
*/
```
