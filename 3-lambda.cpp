#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
  // defining a lambda function and assign it to f
  auto f = [](int& n) { return (n + 1); };
  int n = 3;
  std::cout << f(n) << std::endl;

  // Initialize a vector of size 10 each with value 5
  std::vector<int> v(10, 5);

  // Increase the each number in v by 1
  std::for_each(v.begin(), v.end(), [](int& n) { n += 1; });
  // This should print 6
  std::cout << v[3] << std::endl;

  // Same operation as above. However notice that you don't need to know the
  // type of objects in v. This is good if your container contains objects of
  // different types
  std::for_each(v.begin(), v.end(), [](auto& n) { n += 1; });
  // This should print 7
  std::cout << v[3] << std::endl;

  return 0;
}
