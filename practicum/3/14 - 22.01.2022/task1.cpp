#include <iostream>

bool isDone(int k)
{
  int sum = 0;

  for (size_t i = 1; i < k; i++)
  {
    if (k % i == 0)
    {
      sum += i;
    }
  }
  
  return sum == k + 2;
}

int sumAlmostDone(int a, int b)
{
  int sum = 0;
  int minDone = b + 1;
  int maxDone = a - 1;
  for (size_t i = a; i < b; i++)
  {
    if (isDone(i) && i < minDone)
    {
      minDone = i;
    }

    if (isDone(i) && i > maxDone)
    {
      maxDone = i;
    }
  }

  for (size_t i = (minDone + a) / 2 + 1; i < (b+maxDone)/2; i++)
  {
    sum+= i;
  }
  
  
  return sum;
}

int main()
{
  int a, b;
  std::cin >> a >> b;

  std::cout << sumAlmostDone(a, b) << std::endl;

  return 0;
}