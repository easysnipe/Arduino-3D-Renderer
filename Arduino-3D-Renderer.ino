#include "Arduino_LED_Matrix.h"
#include <vector>
#include <utility>
ArduinoLEDMatrix matrix;

std::vector<std::vector<float>> MatrixMult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
std::vector<int> ToMatrix(std::vector<float> point);
void printVect(std::vector<float> nums);
std::vector<float> transform(std::vector<float> point, std::vector<float> rotations);
std::vector<float> projectTo2D(std::vector<float> point, std::vector<float> pinhole);
void printVec2D(std::vector<std::vector<float>> vec2D);

byte frame[8][12] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


std::vector<std::vector<float>> points =
{
  // Front
  {-0.5f, 0.5f, 0.5f},
  {0.5f, 0.5f, 0.5f},
  {0.5f, -0.5f, 0.5f},
  {-0.5f, -0.5f, 0.5f},
  // Back
  {-0.5f, 0.5f, -0.5f},
  {0.5f, 0.5f, -0.5f},
  {0.5f, -0.5f, -0.5f},
  {-0.5f, -0.5f, -0.5f} 
};

void setup() 
{
  Serial.begin(9600);
  matrix.begin();

}

void clearFrame()
{
  for (int r = 0; r < 8; ++r)
  {
    for (int c = 0; c < 12; ++c)
    {
      frame[r][c] = 0;
    }
  }
}

void loop() 
{
  std::vector<float> rotation = {0.0f, (float)millis() / 1000.0f, 0.0f};
  std::vector<float> pinhole = {0.0f, -10.0f, 0.0f};
  
  Serial.println("Clearing frame");
  clearFrame();
  for (int i = 0; i < points.size(); ++i)
  {
    std::vector<float> point = points[i];
    Serial.println("Transforming Point " + i);
    point = transform(point, rotation);
    Serial.println("Projecting Point " + i);
    point = projectTo2D(point, pinhole);
    
    //Convert to screenspace
    Serial.println("Converting To ScreenSpace " + i);
    std::vector<int> screenP = ToMatrix(point);
    if ((point[0] > 0 && point[0] < 8) && (point[1] > 0 && point[1] < 12))
    {
      frame[screenP[0]][screenP[1]] = 1;
    }
    else
    {
      printVect(point);
    }
  }
  matrix.renderBitmap(frame, 8, 12);
}
