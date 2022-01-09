#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

int main()
{
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    char* sentence = new char[N + 1];
    std::cin.getline(sentence, N + 1);

    int startIndex = 0;
    int maxLength = 0;
    char* longestWord = new char[N + 1];

    for (size_t i = 0; i <= N; i++)
    {
        if ((sentence[i] < 'a' || sentence[i] > 'z')
            && (sentence[i] < 'A' || sentence[i] > 'Z')
            && sentence[i] != '-')
        {
            int wordLength = i - startIndex;

            if (wordLength > maxLength)
            {
                maxLength = wordLength;
                strncpy(longestWord, (sentence + startIndex), maxLength);
                longestWord[maxLength] = '\0';
            }

            startIndex = i + 1;
        }
    }

    std::cout << longestWord << std::endl;

    delete[] sentence;
    delete[] longestWord;
}
