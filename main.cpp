#include <iostream>
#include <vector>
#include <cstdlib>

template <class T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}


int main() {
  std::vector<int> vec;
  for (int i = 0; i < 16; i++) {
    vec.push_back(rand() % 100);
  }

  std::cout << "Before sorting:";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;
}
