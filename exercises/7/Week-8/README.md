# Assignment

## Prerequisites
- [Install C++ Compiler](https://code.visualstudio.com/docs/languages/cpp#_install-a-compiler)
- [Install VSCode](https://code.visualstudio.com/download)
- [Install VSCode C++ Extension](https://code.visualstudio.com/docs/languages/cpp#_install-the-extension)

## Reading Materials
- [Dynamic Memory](https://www.cplusplus.com/doc/tutorial/dynamic/)
- [Abstract Data Types](https://en.wikipedia.org/wiki/Abstract_data_type)
  - [Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
  - [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
  - [Double-ended Queue](https://en.wikipedia.org/wiki/Double-ended_queue)
  - [List](https://en.wikipedia.org/wiki/List_(abstract_data_type))
  - [Set](https://en.wikipedia.org/wiki/Set_(abstract_data_type))

## Recap from Lectures
- [C-Strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)

## Problems

- Write implementations of the following functions from *_strings.h_* (see: [example](https://github.com/triffon/ip-2021-22/blob/master/exercises/7/Week-8/Examples/StringFunctionsExample.cpp))
  - strcpy(s1, s2) - Copies string s2 into string s1.
  - strcat(s1, s2) - Concatenates string s2 onto the end of string s1.
  - strlen(s1) - Returns the length of string s1.
  - strcmp(s1, s2) - Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.
  - strchr(s1, ch) - Returns a pointer to the first occurrence of character ch in string s1.
  - strstr(s1, s2) - Returns a pointer to the first occurrence of string s2 in string s1.
- Write a program that reads a string S (only lowercase latin characters) from STDIN (0 < streln(S) < 1024). At the end of the program write on STDOUT a (see: [histogram](https://en.wikipedia.org/wiki/Histogram)) of S - the the number of times each lowercase latin character can be found in the string (see: [example](https://github.com/triffon/ip-2021-22/blob/master/exercises/7/Week-8/Examples/HistogramExample.cpp)).
- Write a program that reads two strings A and B (only numerical characters) from STDIN (0 < strlen(A),strlen(B) < 20) and writes on STDOUT the string that represents the bigger number (see: [example](https://github.com/triffon/ip-2021-22/blob/master/exercises/7/Week-8/Examples/NumberComparisonExample.cpp)).

## Solutions
Upload solutions in your GitHub folder (see: [how-to](https://www.atlassian.com/git/tutorials/saving-changes/git-commit)) (only .CPP files, no executable files)
