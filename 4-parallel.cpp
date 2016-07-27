#include <vector>
#include <iostream>
#include <parallel/algorithm>
#include <chrono>

// Show the duration elapsed between t_last and now
void show_duration(std::chrono::high_resolution_clock::time_point& t_last,
                   const std::string& name) {
  static auto t_now = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_now - t_last);
  std::cout << "Time for routine '" << name << "' is " << duration.count() << " µs" << std::endl;
  t_last = t_now;
}

int main() {
  // Initialize a large vector
  const int N = 1000000;
  std::vector<int> v(N);

  // Find out the current time
  auto t_start = std::chrono::high_resolution_clock::now();

  // Set element i equal to N - i, in parallel
  __gnu_parallel::for_each(v.begin(), v.end(), [&v](auto& n) {
      n = N - (&n - &v[0]);
    });
  // Sort the elements from small to large, ending up with element at index i
  // equal to i + 1, in parallel
  __gnu_parallel::sort(v.begin(), v.end());

  // This should print 5
  std::cout << v[4] << std::endl;

  // Show the time elapsed since t_start
  show_duration(t_start, "for_each and sort");
  return 0;
}

// This file should be compiled using
//   g++ -std=c++14 -D_GLIBCXX_PARALLEL -fopenmp 4-parallel.cpp
