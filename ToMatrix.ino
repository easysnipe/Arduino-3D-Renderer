#include <vector>

std::vector<int> ToMatrix(std::vector<float> point)
{
  std::vector<int> screenP;
  screenP.push_back(flToMatrix(point[0], true));
  screenP.push_back(flToMatrix(point[1], false));

  return screenP;
}

int flToMatrix(float num, bool x)
{
  num = num / 2;
  num += 0.5f;
  
  return (x) ? (int)num * 12 : (int)num * 8;
}