#include <vector>
std::vector<std::vector<float>> MatrixMult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);

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
  }
  Serial.println(vec3[0].size());

  Serial.println("Multiplying First Matrix");
  rotx = MatrixMult(rotx, roty);
  Serial.println("Multiplying Second Matrix");
  rotz = MatrixMult(rotx, rotz);
  Serial.println("Multiplying Third Matrix");
  vec3 = MatrixMult(rotz, vec3);

  Serial.println("2D to 1D");
  std::vector<float> transPoint;
  for (int i = 0; i < 3; ++i)
  {
    transPoint.push_back(vec3[i][0]);
  }

  Serial.println("Done transformig!");
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

