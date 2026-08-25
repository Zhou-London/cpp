

// * https://cses.fi/problemset/task/1084
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> applicants(n);
  std::vector<int> sizes(m);

  for (int i = 0; i < n; ++i) {
    std::cin >> applicants[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> sizes[i];
  }

  std::sort(applicants.begin(), applicants.end());
  std::sort(sizes.begin(), sizes.end());

  long long ans = 0;
  int l = 0;
  int r = 0;
  while (l < n && r < m) {
    int a = applicants[l];
    if (a > sizes[r] && a - k > sizes[r]) { // ! Use std::abs
      ++r;
    } else if (a < sizes[r] && a + k < sizes[r]) {
      ++l;
    } else if (a - k <= sizes[r] && a + k >= sizes[r]) {
      ++ans;
      ++l;
      ++r;
    }
  }

  std::cout << ans << "\n";
  return 0;
}