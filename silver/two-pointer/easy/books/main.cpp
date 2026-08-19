
#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
//   freopen("books.in", "r", stdin);
//   freopen("books.out", "w", stdout);

  int n, t;
  std::cin >> n >> t;

  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }

  // * Init r to -1
  int l = 0;
  int r = -1;

  int sum = 0;
  int ans = 0;

  while (l < n) {
    // * Check next r
    while (r + 1 < n && sum + vec[r + 1] <= t) {
      ++r;
      sum += vec[r];
    }

    int size = r - l + 1;
    ans = std::max(ans, size);

    sum -= vec[l];
    ++l;
  }

  std::cout << ans << "\n";
}