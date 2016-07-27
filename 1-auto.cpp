#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
  std::vector<int> v(10);
  // Assign the index of each element as the value of that element
  for (auto i = v.begin(); i < v.end(); i++) {
    *i = i - v.begin();
  }

  // This should print 3
  std::cout << v[3] << std::endl;

  return 0;
}

// This file should be compiled using
//   g++ -std=c++11 1-auto.cpp
