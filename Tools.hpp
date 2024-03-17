#ifndef TOOLS_H
#define TOOLS_H

std::vector<std::vector<float>> MatrixMult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
template <typename T> void printVect(const std::vector<T>& nums);
template <typename T> void printVec2D(const std::vector<std::vector<T>>& vec2D);

#endif