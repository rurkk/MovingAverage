#include <gtest/gtest.h>
#include <vector>
#include "MovingAverage.h"

TEST(MovingAverageFloatTest1, HandlesValidInput1) {
  std::vector<float> input = {1.0, 2.0, 3.0, 4.0, 5.0};
  std::vector<float> expectedOutput = {1.5, 2.5, 3.5, 4.5};
  int windowSize = 2;

  std::vector<float> result = moving_average(input, windowSize);
  ASSERT_EQ(result, expectedOutput);
}

TEST(MovingAverageDoubleTest2, HandlesValidInput2) {
  std::vector<double> input = {1.0, 2.0, 3.0, 4.0, 5.0};
  std::vector<double> expectedOutput = {1.5, 2.5, 3.5, 4.5};
  int windowSize = 2;

  std::vector<double> result = moving_average(input, windowSize);
  ASSERT_EQ(result, expectedOutput);
}
