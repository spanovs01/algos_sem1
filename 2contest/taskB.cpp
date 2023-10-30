#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

struct Node {
  long long int current_x;
  long long int current_h;
  Node(long long int current_x, long long int current_h)
      : current_x(current_x), current_h(current_h){};
};

std::vector<long long int> SeparateInt(const std::string& line) {
  std::stringstream ss(line);
  std::string word;
  std::vector<long long int> numbers;
  while (ss >> word) {
    numbers.push_back(std::atoll(word.c_str()));
  }
  return numbers;
}

std::vector<long long int> ReadingInt(const std::string& path) {
  std::string line;
  std::vector<long long int> nums;
  std::vector<std::vector<long long int>> whole;
  std::ifstream in(path);
  if (in.is_open()) {
    std::getline(in, line);
    nums = SeparateInt(line);
  }
  in.close();
  return nums;
}

int main() {
  long long int num;
  long long int max_square = 0;
  long long int square = 0;
  bool flag = false;
  long long int h_last;
  long long int x_last;
  std::vector<long long int> input;
  std::string path = "Binput.txt";
  input = ReadingInt(path);
  num = input[0] + 1;
  input.push_back(0);
  std::stack<Node> st;
  st.push(Node(0, -1));
  long long int current_x = 1;
  while (current_x < num + 1) {
    if (input[current_x] > st.top().current_h) {
      if (!flag) {
        st.push(Node(current_x, input[current_x]));
        ++current_x;
      } else {
        st.push(Node(x_last, input[current_x]));
        flag = false;
        ++current_x;
      }
    } else {
      h_last = st.top().current_h;
      x_last = st.top().current_x;
      st.pop();
      flag = true;
      square = h_last * (current_x - x_last);
    }
    if (square > max_square) {
      max_square = square;
    }
  }
  std::cout << max_square << std::endl;
}