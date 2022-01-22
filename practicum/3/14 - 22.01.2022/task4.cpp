#include <iostream>

bool canBeSummed(int sequence[], int current, int n, int k)
{
  if (k == 0)
  {
    return true;
  }

  if (current >= n)
  {
    return false;
  }

  bool withNumber = canBeSummed(sequence, current + 1, n, k - sequence[current]);
  bool withoutNumber = canBeSummed(sequence, current + 1, n, k);

  return withNumber || withoutNumber;
}

int main()
{
  int n;
  std::cin >> n;

  int* sequence = new int[n];

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> sequence[i];
  }

  int k;
  std::cin >> k;

  std::cout << canBeSummed(sequence, 0, n, k) << std::endl;
  
  delete[] sequence;
  return 0;
}