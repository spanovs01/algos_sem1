#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<double> SeparateDouble(const std::string& line) {
  std::stringstream ss(line);
  std::string word;
  std::vector<double> numbers;
  while (ss >> word) {  // Extract word from the stream.
    numbers.push_back(std::stof(word));
  }
  return numbers;
}

std::vector<int> SeparateInt(const std::string& line) {
  std::stringstream ss(line);
  std::string word;
  std::vector<int> numbers;
  while (ss >> word) {  // Extract word from the stream.
    numbers.push_back(std::stof(word));
  }
  return numbers;
}

std::vector<std::vector<double>> Reading(const std::string& path) {
  std::string line;
  std::vector<double> nums;
  std::vector<std::vector<double>> whole;
  std::ifstream in(path);
  if (in.is_open()) {
    int str_num = 0;
    while (str_num < 2 && std::getline(in, line)) {
      nums = SeparateDouble(line);
      whole.push_back(nums);
      nums.clear();
      str_num += 1;
    }
  }
  in.close();
  return whole;
}

std::vector<std::vector<int>> ReadingInt(const std::string& path) {
  std::string line;
  std::vector<int> nums;
  std::vector<std::vector<int>> whole;
  std::ifstream in(path);
  if (in.is_open()) {
    int str_num = 0;
    while (std::getline(in, line)) {
      if (str_num > 2) {
        nums = SeparateInt(line);
        whole.push_back(nums);
        nums.clear();
      }
      str_num += 1;
    }
  }
  in.close();
  return whole;
}

double GeometricMean(const std::vector<double>& data,
                     const std::pair<int, int>& segm) {
  double product;
  const double kNumber = 2.0;
  double result;
  double power = kNumber / (segm.second - segm.first + 1.0);
  if (segm.first >= 1) {
    product = data[segm.second] / data[segm.first - 1];
  } else {
    product = data[segm.second];
  }
  result = std::pow(product, power);
  return result;
}

void Process() {
  const int kSize = 15;
  std::cout.precision(kSize);
  std::string path = "input.txt";
  std::vector<std::vector<double>> input = Reading(path);
  std::vector<double>& data = input[1];
  std::vector<std::vector<int>> input_int = ReadingInt(path);
  std::vector<std::pair<int, int>> segment;
  std::pair<int, int> pair;
  int input_int_size = input_int.size();
  int data_size = data.size();
  std::vector<double> products;
  const double kNumber = 1.0 / 2.0;
  double new_prod = std::pow(data[0], kNumber);
  products.push_back(new_prod);
  for (int i = 0; i < data_size - 1; ++i) {
    new_prod = std::pow(data[i + 1], kNumber);
    products.push_back(products[i] * new_prod);
  }

  for (int i = 0; i < input_int_size; ++i) {
    pair = std::make_pair(input_int[i][0], input_int[i][1]);
    segment.push_back(pair);
  }
  for (std::pair<int, int>& segm : segment) {
    double res = GeometricMean(products, segm);
    std::cout << res << std::endl;
  }
  segment.clear();
  input.clear();
}

int main() {
  Process();
  return 0;
}