#include <cassert>
#include <iostream>

// узел односвязного списка
struct QueueNode {
  int value;
  QueueNode *next = nullptr;
};

class Queue {
public:
  bool empty() const;
  void push(int value);
  int pop();

private:
  QueueNode *head = nullptr;
  QueueNode *tail = nullptr;
};

void Queue::push(int value) {
  if (empty()) {
    head = tail = new QueueNode{value, nullptr};
  } else {
    tail->next = new QueueNode{value, nullptr};
    tail = tail->next;
  }
}

bool Queue::empty() const {
  assert((head == nullptr) == (tail == nullptr));
  return head == nullptr;
}

int Queue::pop() {
  assert(!empty());
  if (head == tail) {
    // Остался один
    int result = head->value;
    delete head;
    head = tail = nullptr;
    return result;
  }
  int result = head->value;
  QueueNode *next = head->next;
  delete head;
  head = next;
  return result;
}

int main() {
  int commands_count = 0;
  std::cin >> commands_count;
  Queue queue;
  for (int i = 0; i < commands_count; ++i) {
    int comand = 0;
    int value = 0;
    std::cin >> comand >> value;
    if (comand == 3) {
      queue.push(value);
    } else if (comand == 2) {
      if (queue.empty()) {
        if (value != -1) {
          std::cout << "NO";
          return 0;
        }
      } else if (queue.pop() != value) {
        std::cout << "NO";
        return 0;
      }
    }
  }
  std::cout << "YES";
  return 0;
}