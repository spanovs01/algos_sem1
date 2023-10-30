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

void Union(std::pair<int, int>& segm_one, std::pair<int, int>& segm_two) {
    std::vector<std::pair<int,int>> resulting;
    std::pair<int,int> resulting_pair;
    if (segm_two.first < segm_one.second && segm_two.first > segm_one.first) {
        resulting.
    }
    if (segm_two.second < segm_one.second && segm_two.second > segm_one.first) {
        
    }
}

void Process() {
  std::string path = "input_5.txt";
  std::vector<std::vector<int>> input = Reading(path);
  std::vector<std::pair<int, int>> segment;
  std::pair<int, int> pair;
  int input_size = input.size();
  for (int i = 1; i < input_size; ++i) {
    pair = std::make_pair(input[i][0], input[i][1]);
    segment.push_back(pair);
  }
  for (std::pair<int, int>& segm : segment) {
    std::cout << segm.first << " " << segm.second << std::endl;
  }

  Union(segment[0], segment[1]);
}

  int main() {
    Process();
    return 0;
  }