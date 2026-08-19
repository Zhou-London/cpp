
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  // freopen("2sum.in", "r", stdin);
  // freopen("2sum.out", "w", stdout);

  int n, x;
  std::cin >> n >> x;

  // * Use pair to store value and original index
  std::vector<std::pair<int, int>> vec(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i].first;
    vec[i].second = i;
  }

  std::sort(vec.begin(), vec.end());

  int l = 0;
  int r = n - 1;
  while (l < r) {
    int sum = vec[l].first + vec[r].first;

    if (sum < x) {
      ++l;
    } else if (sum > x) {
      --r;
    } else {
      std::cout << vec[l].second + 1 << " " << vec[r].second + 1 << "\n";
      return 0;
    }
  }

  std::cout << "IMPOSSIBLE\n";

  return 0;
}