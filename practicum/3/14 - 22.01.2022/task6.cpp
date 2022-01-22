#include <iostream>
#include <cstring>

bool isWordCharacter(char c)
{
  return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

void proccessTextWords(char* sentence)
{
  int previousWordLength = 0;

  size_t length = strlen(sentence);
  for (size_t i = 0; i < length; i++)
  {
    if (isWordCharacter(sentence[i]))
    {
      int wordStartIndex = i;
      while (isWordCharacter(sentence[i]))
      {
        i++;
      }

      size_t wordLength = i - wordStartIndex;
      if (wordLength < previousWordLength || previousWordLength == 0)
      {
        for (size_t j = 0; j < wordLength; j++)
        {
          std::cout << sentence[j + wordStartIndex];
        }
        std::cout << std::endl;
      }

      previousWordLength = wordLength;
    }
  }
}

int main()
{
  char text[1024];
  std::cin.getline(text, 1024);

  proccessTextWords(text);

  return 0;
}