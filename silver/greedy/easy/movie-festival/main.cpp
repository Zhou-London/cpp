

// * https://cses.fi/problemset/task/1629
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> intervals(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    intervals[i] = {a, b};
  }

  std::sort(intervals.begin(), intervals.end(),
            [](std::pair<int, int> &a, std::pair<int, int> &b) {
              return a.second < b.second;
            });

  long long ans = 1;
  int cur_end = intervals[0].second;
  for (int i = 1; i < n; ++i) {
    if (intervals[i].first >= cur_end) {
      ++ans;
      cur_end = intervals[i].second;
    }
  }

  std::cout << ans << "\n";
  return 0;
}