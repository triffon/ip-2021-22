#include <iostream>

int product_rec(int k)
{
  if (k <= 0)
  {
    return 1;
  }

  return (k % 10) * product_rec(k/10);
}

int product(int k)
{
  if (k == 0)
  {
    return 0;
  }

  return product_rec(k);
}

int main()
{
  std::cout << product(46) << std::endl;
  return 0;
}