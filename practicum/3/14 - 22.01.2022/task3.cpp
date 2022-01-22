#include <iostream>

int knapsack(int costs[], int weights[], int current, int n, int w, int currentWeight)
{
  if (current >= n)
  {
    return 0;
  }

  if (weights[current] + currentWeight > w)
  {
    return 0;
  }

  int costWithItem = costs[current] + knapsack(costs, weights, current + 1, n , w, currentWeight + weights[current]);
  int costWithoutItem = knapsack(costs, weights, current + 1, n, w, currentWeight);

  if (costWithItem > costWithoutItem)
  {
    return costWithItem;
  }

  return costWithoutItem;
}

int main()
{
  return 0;
}