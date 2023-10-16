#include <iostream>
#include <vector>


template<typename T>
std::vector<T> moving_average(const std::vector<T>& data, int window_size) {
  std::vector<T> result(data.size() - window_size + 1);
  T sum = 0;

  for (int i = 0; i < window_size - 1; ++i) {
    sum += data[i];
  }

  sum += data[window_size - 1];
  result[0] = sum / window_size;

  for (int i = window_size; i < data.size(); ++i) {
    sum += data[i];
    sum -= data[i - window_size];
    result[i - window_size + 1] = sum / window_size;
  }

  return result;
}
