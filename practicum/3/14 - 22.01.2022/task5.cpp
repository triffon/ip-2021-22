#include <iostream>
#include <cstring>

// хубав = 0, странен = 1, грозен = 2

int getTextType(char* text)
{
  int counter[26]{ 0 };
  size_t length = strlen(text);

  for (size_t i = 0; i < length; i++)
  {
    counter[text[i]-'a']++;
  }
  
  int minOcc = counter[0], maxOcc = counter[0];

  for (size_t i = 1; i < 26; i++)
  {
    if (counter[i] > maxOcc)
    {
      maxOcc = counter[i];
    }

    if ((counter[i] < minOcc || minOcc == 0) && counter[i] != 0)
    {
      minOcc = counter[i];
    }
  }
  
  if (minOcc == maxOcc)
  {
    return 0;
  }

  if (maxOcc - minOcc == 1)
  {
    int occCounter = 0;
    for (size_t i = 0; i < 26; i++)
    {
      if (counter[i] == maxOcc)
      {
        occCounter++;
      }
    }

    if (occCounter == 1)
    {
      return 1;
    }
  }

  if (minOcc != 1)
  {
    return 2;
  }

  double sum = 0;
  int numbersCount = 0;

  for (size_t i = 0; i < 26; i++)
  {
    if (counter[i] != 0)
    {
      sum += counter[i];
      numbersCount++;
    }
  }
  
  return (maxOcc * (numbersCount - 1)) == (sum - 1) ? 1 : 2;
}

int main()
{
  int n;
  std::cin >> n;
  std::cin.ignore();

  char* text = new char[n];
  std::cin.getline(text, n);

  std::cout << getTextType(text) << std::endl;

  delete[] text;
  return 0;
}