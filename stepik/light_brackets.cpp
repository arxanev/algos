#include <iostream>
#include <stack>

std::pair<char, size_t> ResultVych(const std::string &str) {
  std::stack<std::pair<char, size_t>> stack;
  size_t result = 0;
  for (auto it = str.begin(); it != str.end(); ++it) {
    ++result;
    if (*it == '[' || *it == '{' || *it == '(') {
      stack.push(std::make_pair(*it, result));
    } else if (*it == ']' || *it == '}' || *it == ')') {
      if (stack.empty()) {
        return std::make_pair(' ', result);
      } else if ((*it == ']' && stack.top().first == '[') ||
                 (*it == '}' && stack.top().first == '{') ||
                 (*it == ')' && stack.top().first == '(')) {
        stack.pop();
      } else {
        return std::make_pair(' ', result);
      }
    }
  }
  if (stack.empty()) {
    return std::make_pair(' ', 0);
  } else {
    return stack.top();
  }
}

int main() {
  std::string str;
  std::cin >> str;
  auto answer = ResultVych(str).second;
  if (answer == 0) {
    std::cout << "Success";
  } else {
    std::cout << answer;
  }
}