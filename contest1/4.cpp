#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> Separate(const std::string& line) {
  std::stringstream ss(line);
  std::string word;
  std::vector<int> numbers;
  while (ss >> word) {  // Extract word from the stream.
    numbers.push_back(std::stof(word));
  }
  return numbers;
}

std::vector<std::vector<int>> Reading(const std::string& path) {
  std::string line;
  std::vector<int> nums;
  std::vector<std::vector<int>> whole;
  std::ifstream in(path);
  if (in.is_open()) {
    while (std::getline(in, line)) {
      nums = Separate(line);
      whole.push_back(nums);
      nums.clear();
    }
  }
  in.close();
  return whole;
}

bool IsWorking(std::vector<int>& data, int number, int result) {
  int current_number = 0;
  int index = 0;
  int end;
  int data_size = data.size();
  // std::cout << "result: " << result << ", size: " << data_size << std::endl;
  while (current_number <= number) {
    end = data[index] + result;
    ++current_number;
    // std::cout << "end: " << end << ", current_number: " << current_number
    // << std::endl;
    while (end >= data[index]) {
      // std::cout << "index: " << index << ", data[index]" << data[index]
      // << std::endl;
      if (index >= data_size - 1) {
        return (current_number <= number && index >= data_size - 1);
      }
      ++index;
    }
  }
  return (current_number <= number && index >= data_size - 1);
}

void Process() {
  std::string path = "input_4.txt";
  std::vector<std::vector<int>> input = Reading(path);
  // int number_receiver = input[0][0];
  int number = input[0][1];
  // int number = 5;
  std::vector<int>& data = input[1];
  std::sort(data.begin(), data.end());
  int data_size = data.size();
  int max_result = data[data_size - 1] - data[0];
  int min_result = 1;
  int result;
  bool okay;
  while (min_result != max_result) {
    result = (min_result + max_result) / 2;
    if (result == min_result || result == max_result) {
      break;
    }
    okay = IsWorking(data, number, result);
    // std::cout << "okay: " << okay << std::endl;
    if (okay) {
      max_result = result;
    } else {
      min_result = result;
    }
    // // std::cout << "min_result: " << min_result << ", max_result: " <<
    // max_result
    //           << std::endl;
    // // std::cout << "-----------------------" << std::endl;
  }
  std::cout << max_result << std::endl;
}

int main() {
  Process();
  return 0;
}