

// * https://cses.fi/problemset/task/1074
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }

  std::sort(vec.begin(), vec.end());

  int mid = vec[n / 2];

  long long cost = 0;
  for (const auto &val : vec)
    cost += std::abs(val - mid);

  std::cout << cost << "\n";

  return 0;
}