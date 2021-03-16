#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using vector = std::vector<int>;
using std::string;
using std::stringstream;

int main(void) {
  vector numbers;
  string input;
  int temp;
  int sum = 0;

  std::cout << "Input variadic numbers separated by SPACE: ";
  std::getline(std::cin, input);

  stringstream iss(input);

  while (iss >> temp)
    numbers.push_back(temp);

  for (const auto &it : numbers)
    sum += it;

  std::cout << "Sum of the numbers: " << sum << std::endl;

  return 0;
}