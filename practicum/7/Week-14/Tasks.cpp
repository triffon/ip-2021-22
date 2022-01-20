#include <iostream>
#include <cstring>

/*нека имаме низът "aaaabbbdZZZZZgggg". Важното е низът да не съдържа цифри. 
Заместваме всяка непрекъсната последователност от символи X с низа XN, където N е дължината на последователността. 
Единичните символи не се заменят.
Тоест примерния низ ще се трансформира до “a4b3dZ5g4”.
Реализирайте функция, която компресира низoве по горния начин. Функцията приема низ и връща компресирания низ 
(искаме копресираният низ да е динамично заделен с точна дължина).*/
char* task1(char* str) {
    char* temp = new char[strlen(str) * 2];
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int count = 1;
        while (str[i] == str[i + 1]) {
            i++;
            count++;
        }
        temp[index++] = str[i];
        temp[index] = '\0';
        char number[100];
        itoa(count, number, 10);
        strcat_s(temp, sizeof temp + strlen(number) + 1, number); // sizeof temp + 1
        index += strlen(number);
    }
    char* result = new char[strlen(temp) + 1];
    strcpy_s(result, strlen(temp) + 1, temp);
    delete[] temp;

    return result;
}

/*https://ibb.co/wJ5qwfy*/
unsigned countDuplicates(const char* str)
{
    unsigned len = strlen(str);
    unsigned counter = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            counter++;
            continue;
        }
        for (size_t j = 0; j < len; j++)
        {
            if (str[i] == str[j] && i != j)
            {
                counter++;
                break;
            }
        }
    }
    return counter;
}
char* getDuplicates(const char* str)
{
    unsigned len = strlen(str);
    unsigned newLen = countDuplicates(str);
    char* result = new char[newLen + 1];
    unsigned resultIndex = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            result[resultIndex++] = str[i];
            continue;
        }
        for (size_t j = 0; j < len; j++)
        {
            if (str[i] == str[j] && i != j)
            {
                result[resultIndex++] = str[i];
                break;
            }
        }
    }
    result[resultIndex] = '\0';
    return result;
}

unsigned countWords(const char* str, char** matrix, unsigned dimension) //diagonals traversal, task from your group with the 4K quality
{
    unsigned counter = 0;

    char** words = nullptr;
    unsigned rowsWords = 0;
    //getWords(str, words, rowsWords); words into matrix (do it on your own :) )

    int x = dimension - 1, y = 0;
    while (x >= 0)
    {
        char* currentWord = new char[dimension + 1];
        unsigned currWordInd = 0;
        for (size_t i = x, j = 0; i <= dimension - 1; i++, j++)
        {
            currentWord[currWordInd++] = matrix[i][j];
        }
        currentWord[currWordInd] = '\0';
        for (size_t i = 0; i < rowsWords; i++)
        {
            if (strcmp(words[i], currentWord) == 0)
            {
                counter++;
                break;
            }
        }
        delete[] currentWord;
        x--;
    }

    x = 0, y = 1;
    while (y <= dimension - 1)
    {
        char* currentWord = new char[dimension + 1];
        unsigned currWordInd = 0;
        for (size_t i = 0, j = y; j <= dimension - 1; i++, j++)
        {
            currentWord[currWordInd++] = matrix[i][j];
        }
        currentWord[currWordInd] = '\0';
        for (size_t i = 0; i < rowsWords; i++)
        {
            if (strcmp(words[i], currentWord) == 0)
            {
                counter++;
                break;
            }
        }
        delete[] currentWord;
        y++;
    }

    x = dimension - 1, y = dimension - 1;
    while (x >= 0)
    {
        char* currentWord = new char[dimension + 1];
        unsigned currWordInd = 0;
        for (size_t i = x, j = y; i <= dimension - 1; i++, j--)
        {
            currentWord[currWordInd++] = matrix[i][j];
        }
        currentWord[currWordInd] = '\0';
        for (size_t i = 0; i < rowsWords; i++)
        {
            if (strcmp(words[i], currentWord) == 0)
            {
                counter++;
                break;
            }
        }
        delete[] currentWord;
        x--;
    }

    x = 0, y = 1;
    while (y <= dimension - 1)
    {
        char* currentWord = new char[dimension + 1];
        unsigned currWordInd = 0;
        for (size_t i = x, j = y; j <= dimension - 1; i++, j--)
        {
            currentWord[currWordInd++] = matrix[i][j];
        }
        currentWord[currWordInd] = '\0';
        for (size_t i = 0; i < rowsWords; i++)
        {
            std::cout << words[i] << " ";
            if (strcmp(words[i], currentWord) == 0)
            {
                counter++;
                break;
            }
        }
        delete[] currentWord;
        y--;
    }

    return counter;
}

int main() {
    /*int n;
    std::cin >> n;
    char* str = new char[n];
    std::cin >> str;
    char* result = task1(str);
    std::cout << result;
    //Task 1
    delete[] result;*/

    //getDuplicates...
}