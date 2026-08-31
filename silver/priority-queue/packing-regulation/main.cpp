

// * https://atcoder.jp/contests/abc214/tasks/abc214_e
// ? Priority Queue, Greedy, Sorting

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int T;
  std::cin >> T;
  while (T--) {
    int N;
    std::cin >> N;

    struct Interval {
      int l;
      int r;
    };

    std::vector<Interval> intervals(N);
    for (int i = 0; i < N; ++i) {
      int l, r;
      std::cin >> l >> r;

      intervals[i] = {l, r};
    }

    std::sort(intervals.begin(), intervals.end(),
              [](const Interval &a, const Interval &b) { return a.l < b.l; });

    auto cmp = [](const Interval &a, const Interval &b) { return a.r > b.r; };
    std::priority_queue<Interval, std::vector<Interval>, decltype(cmp)> pq(cmp);

    int box_idx = 0; // next box
    int i = 0;       // next interval

    while (i < N || !pq.empty()) {
      if (pq.empty()) {
        box_idx = intervals[i].l;
      }

      while (i < N && intervals[i].l <= box_idx) {
        pq.push(intervals[i]);
        ++i;
      }

      // ! Check the interval with lowest R
      if (!pq.empty() && pq.top().r < box_idx) {
        std::cout << "No\n";
        break;
      } else {
        pq.pop();
        ++box_idx; // ! Move ahead
      }
    }

    if (pq.empty() && i == N)
      std::cout << "Yes\n";
  }

  return 0;
}