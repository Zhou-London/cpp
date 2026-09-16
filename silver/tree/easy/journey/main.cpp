

// * https://codeforces.com/contest/839/problem/C
// ? Tree, DFS, DP

#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto DFS = [&](auto &&self, int u, int father) -> double {
    double sum = 0; // Child's value
    int cnt = 0;
    for (int v : adj[u]) {
      if (v == father)
        continue; // Skip father
      sum += self(self, v, u);
      ++cnt;
    }

    if (cnt == 0)
      return 0;
    return 1 + sum / cnt; // Child's E
  };

  std::cout << DFS(DFS, 1, 0) << "\n";
}