#include <vector>

std::vector<std::vector<int>> ToMatrix(std::vector<std::vector<float>> points)
{
  std::vector<std::vector<int>> matrixPoints;
  for (int i = 0; i < points.size(); ++i)
  {
    std::vector<int> point;
    point.push_back(flToMatrix(points[i][0], true));
    point.push_back(flToMatrix(points[i][1], false));

    matrixPoints.push_back(point);
  }

  return matrixPoints;
}

int flToMatrix(float num, bool x)
{
  num = num / 2;
  num += 0.5f;
  
  return (x) ? (int)num * 12 : (int)num * 8;
}