#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Point {
  int value;
  int index;
};

bool ComparePoints(Point structure_a, Point structure_b) {
  return structure_a.value < structure_b.value;
}

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

void Process() {
  std::string path = "input.txt";
  std::vector<std::vector<int>> input = Reading(path);
  std::vector<int>& data = input[1];
  std::vector<std::pair<int, int>> segment;
  std::pair<int, int> pair;
  int input_size = input.size();
  int data_size = data.size();
  std::vector<Point> entity;
  for (int i = 0; i < data_size; ++i) {
    entity.push_back(Point());
    entity[i].value = data[i];
    entity[i].index = i + 1;
  }
  for (int i = 3; i < input_size; ++i) {
    pair = std::make_pair(input[i][0], input[i][1]);
    segment.push_back(pair);
  }
  //   for (std::pair<int, int>& segm : segment) {
  //     std::cout << segm.first << " " << segm.second << std::endl;
  //   }
  //   for (int i = 0; i < data_size; ++i) {
  //     std::cout << entity[i].value << " " << entity[i].index << std::endl;
  //   }
  std::sort(entity.begin(), entity.end(), ComparePoints);
  //   for (std::pair<int, int>& segm : segment) {
  //     std::cout << segm.first << " " << segm.second << std::endl;
  //   }
  //   for (int i = 0; i < data_size; ++i) {
  //     std::cout << entity[i].value << " " << entity[i].index << std::endl;
  //   }
  int segment_size = segment.size();
  for (int j = 0; j < segment_size; ++j) {
    for (int i = 0; i < data_size; ++i) {
      if (entity[i].index <= segment[j].first ||
          entity[i].index >= segment[j].second) {
        std::cout << entity[i].value << std::endl;
        break;
      }
    }
  }
  input.clear();
  entity.clear();
  segment.clear();
}

int main() {
  Process();
  return 0;
}