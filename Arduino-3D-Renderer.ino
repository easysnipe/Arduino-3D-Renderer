#include "Arduino_LED_Matrix.h"
#include <vector>
#include <utility>
#include "ThreeD.hpp"
#include "Tools.hpp"
#include "ToMatrix.hpp"

ArduinoLEDMatrix matrix;

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

// Cube Vertices Defined in NDC
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
  Serial.begin(57600);
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
  std::vector<float> pinhole = {0.0f, 0.0f, -1.0f};
  
  clearFrame();
  for (int i = 0; i < points.size(); ++i)
  {
    std::vector<float> point = points[i];

    // Apply rotation to points
    point = transform(point, rotation);
    point[2] += 1.25f;

    // Project to 2D
    point = projectTo2D(point, pinhole);
    
    //Convert to screenspace
    std::vector<int> screenP = ToMatrix(point);
    
    // Add to bitmap if within range
    if ((screenP[0] >= 0 && screenP[0] < 12) && (screenP[1] >= 0 && screenP[1] < 8))
    {
      frame[screenP[1]][screenP[0]] = 1;
    }
  }

  matrix.renderBitmap(frame, 8, 12);
}

