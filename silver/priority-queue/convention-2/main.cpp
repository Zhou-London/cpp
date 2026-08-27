

// * https://usaco.org/index.php?page=viewproblem2&cpid=859
// ? Priority Queue

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

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

  std::sort(cows.begin(), cows.end(),
            [](const Cow &a, const Cow &b) { return a.a < b.a; });

  auto cmp = [](const Cow &a, const Cow &b) { return a.s > b.s; };
  std::priority_queue<Cow, std::vector<Cow>, decltype(cmp)> pq(cmp);

  long long end = 0;
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    auto &cow = cows[i];

    while (!pq.empty() && pq.top().a < end) {
      long long wait = end - pq.top().a;
      ans = std::max(ans, wait);

      end += pq.top().t;
      pq.pop();
    }

    if (cow.a >= end) {
      end = cow.a + cow.t;
    } else {
      pq.push(cow);
    }
  }

  std::cout << ans << "\n";
  return 0;
}