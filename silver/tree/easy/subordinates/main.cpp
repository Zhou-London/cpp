

// * https://cses.fi/problemset/task/1674
// ? Tree

#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> adj(n + 1);

  for (int i = 2; i <= n; ++i) {
    int boss;
    std::cin >> boss;
    adj[boss].push_back(i);
  }

  std::vector<int> sz(n + 1, 0);

  auto DFS = [&](auto &&self, int cur) -> void {
    sz[cur] = 1;
    for (int next : adj[cur]) {
      self(self, next);
      sz[cur] += sz[next];
    }
  };

  DFS(DFS, 1);

  for (int i = 1; i <= n; ++i)
    std::cout << sz[i] - 1 << " ";

  std::cout << "\n";
  return 0;
}