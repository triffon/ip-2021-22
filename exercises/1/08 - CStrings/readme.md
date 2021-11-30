# Ex08 - CStrings

An array of characters ending with a null terminator ('\0')

## Differences with regular arrays

- No need to pass an end / size to use them. Just look for the null terminator.

```c++
char word[]{"kappa"};
std::cout << sizeof(word); // 6: 5 letters + \0
```

- Overloaded operator<<

```c++
int arr[] = {1, 2, 3};
std::cout << arr; // arr decays to a pointer and this prints the adress of the first element

char word[]{"kappa"};
std::cout << word; // Prints: kappa
```

- Overloaded operator>>

```c++
char word[100];
std::cin >> word; // Input: kappa
std::cout << word; // kappa

// >> ignores white space
std::cin >> word; // input: kappa 123
std::cout << word; // kappa

// Use getline to also read the white space

std::cin.getline(word, 100); // kappa 123
std::cout << word; // kappa 123

// You can also pass a delimiter that stops the reading
std::cin.getline(word, 100, '!'); // kappa!123
std::cout << word; // kappa
```

- Never remove the null terminator

```c++
char word[]{'kappa'};
word[5] = '!';
std::cout << word; // Undefined behaviour
```

- cstring library https://en.cppreference.com/w/cpp/header/cstring


## Problems

### 00 - Some standard fuctions
Implement the following functions from the standard library
- strlen
- strcpy
- strcmp
- strcat
- strchr
- strstr

### 01 - Reverse words

Given a sentence where every word is separated by a single interval, reverse the individual words in the sentence, without reversing their order.

Return the reversed sentence.

#### Example

```c++
char sentence[100]{"Turn that frown upside down :("};
std::cout << reverse_words(sentence); // nruT taht nworf edispu nwod (:
```

### 02 - atoi

Given a string that starts with an integer, return the integer and ignore the rest of the string

#### Example

```c++
std::cout << atoi("123filler") + atoi("-81morefiller") << '\n'; // 42
```

### 03 - Run Length Decode

Given a string that contains numbers and lowercase latin characters, "decode" the string by replacing every instance of {number}{character} in the string with {number} copies of {character}. Write the new string in a given buffer and return the new buffer.

#### Example

```c++
char buffer[100]{};
std::cout << run_length_decode(buffer, "a2b10c"); // abbcccccccccc
```