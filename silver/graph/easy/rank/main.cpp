

// * https://dmoj.ca/problem/acsl1p4
// ? DFS, Cyclic

#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int N, K;
  std::cin >> N >> K;

  std::vector<std::vector<int>> adj(N + 1);
  for (int i = 0; i < K; ++i) {
    int a, b, s1, s2;

    std::cin >> a >> b >> s1 >> s2;

    if (s1 > s2)
      adj[a].push_back(b);
    else
      adj[b].push_back(a);
  }

  int ans = 0;

  for (int i = 1; i <= N; ++i) {
    std::vector<bool> visited(N + 1, false);
    bool cyclic = false;

    // ! DFS deduplication
    auto dfs = [&](auto &&self, int curr) -> void {
      visited[curr] = true;
      
      for (int next : adj[curr]) {
        if (next == i) {
          cyclic = true;
          return;
        }
        if (!visited[next])
          self(self, next);
      }
    };

    dfs(dfs, i);

    if (cyclic)
      ++ans;
  }

  std::cout << ans << "\n";
  return 0;
}