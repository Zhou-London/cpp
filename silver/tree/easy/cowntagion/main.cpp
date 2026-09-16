

// * https://usaco.org/index.php?page=viewproblem2&cpid=1062
// ? Tree, Ad-hoc

#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<int> degrees(N + 1, 0);
  std::vector<int> children_cnt(N + 1, 0);
  for (int i = 0; i < N - 1; ++i) { // ! Edges are N-1
    int u, v;
    std::cin >> u >> v; // ! Undirected

    ++degrees[u];
    ++degrees[v];
  }

  children_cnt[1] = degrees[1];
  for (int i = 2; i <= N; ++i) {
    children_cnt[i] = degrees[i] - 1;
  }

  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (!children_cnt[i])
      continue;

    int cows = 1;
    int spread_days = 0;
    while (cows < 1 + children_cnt[i]) { // ! Count itself
      cows *= 2;
      ++spread_days;
    }

    ans += spread_days + children_cnt[i];
  }

  std::cout << ans << "\n";
  return 0;
}