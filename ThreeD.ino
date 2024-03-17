#include <vector>
#include "ThreeD.hpp"
#include "Tools.hpp"

std::vector<float> transform(std::vector<float> point, std::vector<float> rotations)
{
  std::vector<std::vector<float>> rotx =
  {
    {1, 0, 0},
    {0, cos(rotations[0]), sin(rotations[0])},
    {0, -sin(rotations[0]), cos(rotations[0])}
  };
  std::vector<std::vector<float>> roty =
  {
    {cos(rotations[1]), 0, -sin(rotations[1])},
    {0, 1, 0},
    {sin(rotations[1]), 0, cos(rotations[1])}
  };
  std::vector<std::vector<float>> rotz = 
  {
    {cos(rotations[2]), sin(rotations[2]), 0},
    {-sin(rotations[2]), cos(rotations[2]), 0},
    {0, 0, 1}
  };
  std::vector<std::vector<float>> vec3;
  for (int i = 0; i < 3; ++i)
  {
    std::vector<float> row;
    row.push_back(point[i]);
    vec3.push_back(row);
  }

  // Apply Rotations
  rotx = MatrixMult(rotx, roty);
  rotz = MatrixMult(rotx, rotz);
  vec3 = MatrixMult(rotz, vec3);

  std::vector<float> transPoint;
  for (int i = 0; i < 3; ++i)
  {
    transPoint.push_back(vec3[i][0]);
  }

  return transPoint;
}

std::vector<float> projectTo2D(std::vector<float> point, std::vector<float> pinhole)
{
  std::vector<float> point2D;
  float x = (pinhole[2] / point[2]) * point[0] + pinhole[0];
  float y = (pinhole[2] / point[2]) * point[1] + pinhole[1]; 
  point2D.push_back(x);
  point2D.push_back(y);
  return (point2D);
}

