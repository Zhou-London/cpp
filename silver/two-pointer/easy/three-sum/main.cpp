#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
//   freopen("3sum.in", "r", stdin);
//   freopen("3sum.out", "w", stdout);

  int n, x;
  std::cin >> n >> x;

  std::vector<std::pair<int, int>> vec(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i].first;
    vec[i].second = i + 1;
  }

  std::sort(vec.begin(), vec.end());

  for (int i = 0; i < n - 2; ++i) {
    int l = i + 1;
    int r = n - 1;

    // * 2 sum problem
    while (l < r) {
      int sum = vec[l].first + vec[r].first + vec[i].first;
      if (sum > x) {
        --r;
      } else if (sum < x) {
        ++l;
      } else {
        std::cout << vec[l].second << " " << vec[r].second << " "
                  << vec[i].second << "\n";

        return 0;
      }
    }
  }

  std::cout << "IMPOSSIBLE\n";

  return 0;
}