

// * https://usaco.org/index.php?page=viewproblem2&cpid=714
// ?

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("helpcross.in", "r", stdin);
  freopen("helpcross.out", "w", stdout);

  int C, N;
  std::cin >> C >> N;

  std::vector<int> chicken(C);
  for (int i = 0; i < C; ++i) {
    std::cin >> chicken[i];
  }

  std::sort(chicken.begin(), chicken.end());

  struct Inter {
    int l;
    int r;
  };

  std::vector<Inter> inters(N);
  for (int i = 0; i < N; ++i) {
    int l, r;
    std::cin >> l >> r;

    inters[i] = {l, r};
  }

  std::sort(inters.begin(), inters.end(),
            [](const Inter &a, const Inter &b) { return a.l < b.l; });

  auto cmp = [](const Inter &a, const Inter &b) { return a.r > b.r; };
  std::priority_queue<Inter, std::vector<Inter>, decltype(cmp)> pq(cmp);

  int ni = 0; // cow index
  long long ans = 0;

  for (int i = 0; i < C; ++i) {
    // ! No need to move i manually

    while (ni < N && inters[ni].l <= chicken[i]) {
      pq.push(inters[ni]);
      ++ni;
    }

    while (!pq.empty()) {
      if (pq.top().r >= chicken[i]) {
        pq.pop();
        ++ans;
        break;
      }
      pq.pop();
    }
  }

  std::cout << ans << "\n";
  return 0;
}