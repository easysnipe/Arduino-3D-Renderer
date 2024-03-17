#include <utility>
#include <algorithm>
#include <vector>

std::vector<std::vector<float>> MatrixMult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2)
{ 
  std::vector<std::vector<float>> productMatrix;
  for (int r = 0; r < matrix1.size(); ++r)
  {
    std::vector<float> row;
    for (int c = 0; c < matrix2[0].size(); ++c)
    {
      float product = 0;
      for (int curr = 0; curr < matrix2.size(); ++curr)
      {
        product += matrix1[r][curr] * matrix2[curr][c];
      }
      row.push_back(product);
    }
    productMatrix.push_back(row);
  }

  return productMatrix;
}

void printVect(std::vector<float> nums)
{
  Serial.print("{ ");
  for (float curr : nums)
  {
    Serial.print(curr);
    Serial.print(", ");
  }
  Serial.println("}");
}

void printVec2D(std::vector<std::vector<float>> vec2D)
{
  for (std::vector<float> vec : vec2D)
  {
    printVect(vec);
  }
}