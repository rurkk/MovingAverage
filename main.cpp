#include <iostream>
#include <vector>
#include <chrono>
#include "MovingAverage.h"


std::vector<double> generateTestData(int dataSize) {
  std::vector<double> data;
  for (int i = 0; i < dataSize; ++i) {
    data.push_back(static_cast<double>(rand()) / RAND_MAX);
  }
  return data;
}

template<typename T>
double measurePerformance(const std::vector<T>& data, int window_size) {
  auto start = std::chrono::high_resolution_clock::now();
  moving_average(data, window_size);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  return duration.count();
}

int main() {
  int dataSize = 1000000;
  std::vector<double> data = generateTestData(dataSize);
  std::vector<int> windowSizes = {2, 4, 8, 16, 32, 64, 128};

  for (int windowSize : windowSizes) {
    double timeDouble = measurePerformance(data, windowSize);
    std::cout << "For window size " << windowSize << " and double data type, time taken: " << timeDouble << " seconds\n";

    std::vector<float> floatData(data.begin(), data.end());
    double timeFloat = measurePerformance(floatData, windowSize);
    std::cout << "For window size " << windowSize << " and float data type, time taken: " << timeFloat << " seconds\n";
  }

  return 0;
}





