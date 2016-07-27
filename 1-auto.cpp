#include <iostream>
#include <vector>

// This only works in c++14, in c++11 one needs to write
// auto f(int n) -> decltype(n)
auto f(int n) {
  return (n + 1);
}

int main(int argc, char *argv[])
{
  std::vector<int> v(10);
  // Assign the index of each element as the value of that element
  for (auto i = v.begin(); i < v.end(); i++) {
    *i = i - v.begin();
  }

  // This should print 3
  std::cout << f(v[3]) << std::endl;

  return 0;
}

// This file should be compiled using
//   g++ -std=c++14 1-auto.cpp
