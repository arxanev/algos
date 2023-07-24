#include <iostream>
#include <stack>
#include <utility>

std::pair<char, size_t> Chec(const std::string str) {
  std::stack<std::pair<char, size_t>> stack;
  size_t count = 0;
  if (str.empty()) {
    return;
  }
  for (auto it = str.begin(); it != str.end(); ++it) {
    ++count;
    if (*it == '[' || *it == '{' || *it == '(') {
      stack.push(std::make_pair(*it, count));
    } else {
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string str;
  std::cin >> str;
  auto res = Chec(str).second;
  if (res == 0) {
    std::cout << "CORRECT";
  } else {
    std::cout << res;
  }
}