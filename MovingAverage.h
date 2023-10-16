#include <iostream>
#include <vector>


template<typename T>
std::vector<T> moving_average(const std::vector<T>& data, int window_size) {
  std::vector<T> result;
  T sum = 0;

  for (int i = 0; i < data.size(); ++i) {
    sum += data[i];
    if (i >= window_size) {
      sum -= data[i - window_size];
      result.push_back(sum / window_size);
    } else if (i == window_size - 1) {
      result.push_back(sum / window_size);
    }
  }

  return result;
}
