#include <iostream>
#include <cstring>

const int MAX_INPUT_SIZE = 1024;

// checks whether the given character is a letter
inline bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

// counts the number of words in a given string
int countWords(const char* str)
{
    int count = 0;
    while (*str)
    {
        while (*str && !isLetter(*str))
            ++str;
        
        if (*str)
            ++count;
        
        while (isLetter(*str))
            ++str;
    }

    return count;
}

// strcpy, but only copies the word part of the string (from the beginning)
// returns number of copied characters
int strCpyWord(char* dest, const char* src)
{
    int count = 0;
    while (*src && isLetter(*src))
    {
        *dest = *src;
        ++dest;
        ++src;
        ++count;
    }
    *dest = '\0';

    return count;
}

// copies the next word in str to word
// moving the original pointer
bool getNextWord(char* outWord, const char*& str)
{
    while (*str && !isLetter(*str))
        ++str;

    if (*str)
    {
        str += strCpyWord(outWord, str);
        return true;
    }

    return false;
}

// deleting allocated matrix
void cleanMatrix(char**& matrix, int size)
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];

    delete[] matrix;
    matrix = nullptr;
}

// returns index of the first encounter of target in matrix or -1
int findWord(const char* const* matrix, int size, const char* target)
{
    for (int i = 0; i < size; i++)
        if (strcmp(matrix[i], target) == 0)
            return i;

    return -1;
}

// returns the index of the maximal element in arr from startIndex
int getMaxIndexFrom(const int* arr, int size, int startIndex)
{
    int maxIndex = startIndex;
    for (int i = startIndex + 1; i < size; i++)
        if (arr[i] > arr[maxIndex])
            maxIndex = i;

    return maxIndex;
}

// sorts matrix by the given frequency array and size
void sortByFreq(char** matrix, int* freq, int size)
{
    // selection sort
    for (int i = 0; i < size - 1; i++)
    {
        int ind = getMaxIndexFrom(freq, size, i);
        if (i != ind)
        {
            std::swap(matrix[i], matrix[ind]);
            std::swap(freq[i], freq[ind]);
        }
    }
}

//------------------------------------------------------------------------------
int main()
{
    // Read the input
    char input[MAX_INPUT_SIZE];
    std::cin.getline(input, MAX_INPUT_SIZE);

    // Count the number of words
    int numOfWords = countWords(input);

    // Create matrix with numOfWords rows
    char** words = new (std::nothrow) char*[numOfWords];

    if (!words) {
        std::cout << "Not enough memory!\n";
        return 1;
    }

    // Create an array with size numOfWords to keep their count
    int* wordCountArr = new (std::nothrow) int[numOfWords];

    if (!wordCountArr) {
        delete[] words;
        std::cout << "Not enough memory!\n";
        return 1;
    }

    // counting the unique words
    int numOfUniqueWords = 0;

    // buffer for reading the words from the input
    char buffer[MAX_INPUT_SIZE];

    // pointer pointing to the current reached position in the input
    const char* inputPtr = input;

    // Adding words to the matrix
    for (int i = 0; i < numOfWords; i++)
    {
        // next word from the input is stored in buffer
        if (getNextWord(buffer, inputPtr)) 
        {
            int ind = findWord(words, i, buffer);
            if (ind == -1)
            {   // If that's a new word
                // create a new string in the matrix
                words[i] = new (std::nothrow) char[strlen(buffer) + 1];
                if (!words[i])
                {
                    std::cout << "Not enough memory!\n";
                    cleanMatrix(words, i);
                    delete[] wordCountArr;
                    return 1;
                }

                // Set it's count to 1
                wordCountArr[i] = 1;

                // Copy it to the matrix
                strCpyWord(words[i], buffer);

                // Count as unique word
                ++numOfUniqueWords;
            }
            else
            {
                // If the word wasn't unique, increment the count
                ++wordCountArr[ind];
                // And move i back so we don't have empty rows in the beginning
                --i;
            }
        }
        else
        {
            // If there aren't any words found
            // make any rows remaining a nullptr
            words[i] = nullptr;
            wordCountArr[i] = 0;
        }
    }

    // Sort
    sortByFreq(words, wordCountArr, numOfUniqueWords);

    // Print
    for (int i = 0; i < numOfWords; i++)
        std::cout << words[i] << ' ';

    // Don't forget to delete your memory!
    cleanMatrix(words, numOfWords);
    delete[] wordCountArr;
    
    return 0;
}
