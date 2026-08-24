

// * https://usaco.org/index.php?page=viewproblem2&cpid=896
// ? Sort, Custom Comparator, Mathematics

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
int main() {
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<std::pair<long long, long long>> intervals(N);
  for (int i = 0; i < N; ++i) {
    long long x, y;
    std::cin >> x >> y;

    // ! Transform
    long long l = x - y;
    long long r = x + y;

    intervals[i] = {l, r};
  }

  std::sort(intervals.begin(), intervals.end(),
            [&](std::pair<long long, long long> a,
                std::pair<long long, long long> b) {
              if (a.first == b.first)
                return a.second > b.second; // Desc
              else
                return a.first < b.first; // Asc
            });

  long long ans = 1;
  long long max_second = intervals[0].second;

  // ! Compare with max
  for (int i = 0; i + 1 < N; ++i) {
    if (intervals[i + 1].second > max_second) {
      ++ans;

      max_second = intervals[i + 1].second;
    }
  }

  std::cout << ans << "\n";
  return 0;
}