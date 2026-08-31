

// * https://usaco.org/index.php?page=viewproblem2&cpid=859
// ? Priority Queue, Sorting

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("convention2.in", "r", stdin);
  freopen("convention2.out", "w", stdout);

  struct Cow {
    int a;
    int t;
    int s; // senior
  };

  int N;
  std::cin >> N;

  std::vector<Cow> cows(N);
  for (int i = 0; i < N; ++i) {
    int a, t;
    std::cin >> a >> t;

    cows[i] = {a, t, i};
  }

  std::sort(cows.begin(), cows.end(), [](const Cow &a, const Cow &b) {
    return a.a < b.a;
  }); // ! Sort by arrivial time

  auto cmp = [](const Cow &a, const Cow &b) { return a.s > b.s; };
  std::priority_queue<Cow, std::vector<Cow>, decltype(cmp)> pq(cmp);

  int i = 0;
  int end = 0;
  long long ans = 0;

  while (i < N || !pq.empty()) {
    while (i < N && cows[i].a <= end) { // ! Push every waiting cow
      pq.push(cows[i]);
      ++i;
    }

    if (pq.empty()) {
      end = cows[i].a + cows[i].t;
      ++i;
    } else {
      ans = std::max<long long>(ans, end - pq.top().a);
      end += pq.top().t;
      pq.pop();
    }
  }

  std::cout << ans << "\n";

  return 0;
}