#include <utility>
#include <algorithm>
#include <vector>
#include "Tools.hpp"

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

template <typename T> void printVect(const std::vector<T>& nums)
{
  Serial.print("{ ");
  for (const auto& curr : nums)
  {
    Serial.print(curr);
    Serial.print(", ");
  }
  Serial.println("}");
}

template <typename T> void printVec2D(const std::vector<std::vector<T>>& vec2D)
{
  for (const auto& vec : vec2D)
  {
    printVect(vec);
  }
}