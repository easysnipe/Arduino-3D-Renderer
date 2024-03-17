#include "Arduino_LED_Matrix.h"
#include <vector>
#include <utility>
ArduinoLEDMatrix matrix;

std::vector<std::vector<float>> MatrixMult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
std::vector<std::vector<int>> ToMatrix(std::vector<std::vector<float>> points);
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

void loop() 
{
  matrix.renderBitmap(frame, 8, 12);
}
