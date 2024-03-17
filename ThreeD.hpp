#ifndef THREED_H
#define THREED_H

std::vector<float> transform(std::vector<float> point, std::vector<float> rotations);
std::vector<float> projectTo2D(std::vector<float> point, std::vector<float> pinhole);

#endif