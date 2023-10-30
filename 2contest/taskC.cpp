#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int line_num = 0;
  std::vector<int> result;
  std::string line;
  std::getline(std::cin, line);
  std::deque<int> first_deq = {};
  std::deque<int> second_deq = {};
  int num = std::stoi(line);
  ++line_num;
  while (line_num <= num) {
    std::getline(std::cin, line);
    ++line_num;
    if (line[0] == '+') {
      line.erase(0, 2);
      first_deq.push_back(std::stoi(line));
    } else if (line[0] == '*') {
      line.erase(0, 2);
      first_deq.push_front(std::stoi(line));
    } else {
      result.push_back(second_deq[0]);
      second_deq.pop_front();
    }
    if (second_deq.size() < first_deq.size()) {
      second_deq.push_back(first_deq[0]);
      first_deq.pop_front();
    }
  }
  for (int res : result) {
    std::cout << res << std::endl;
  }
}