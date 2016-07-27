#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
  std::vector<int> v(10);
  // Assign the id to each element of v
  for (int& n : v) {
    n = &n - &v[0];
  }
  // This should print 3
  std::cout << v[3] << std::endl;

  return 0;
}

