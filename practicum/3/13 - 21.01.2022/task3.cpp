#include <iostream>

int getHeighestTower(int* boxes, int n, int currentBoxIndex, int previousBoxSize)
{
  if (currentBoxIndex >= n)
  {
    return 0;
  }

  if (previousBoxSize < boxes[currentBoxIndex])
  {
    return 0;
  }

  int withBoxHeight = boxes[currentBoxIndex] 
        + getHeighestTower(boxes, n, currentBoxIndex + 1, boxes[currentBoxIndex]);

  int withoutBoxHeight = getHeighestTower(boxes, n, currentBoxIndex + 1, previousBoxSize);

  if (withBoxHeight > withoutBoxHeight)
  {
    return withBoxHeight;
  }

  return withoutBoxHeight;
}

int main()
{
  int boxes[100];
  int n;

  std::cin >> n;

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> boxes[i];
  }
  
  getHeighestTower(boxes, n, 0, 999999999999);
}