

// * https://cses.fi/problemset/task/1131/
// ? Tree, Traversal

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);

  // ! n-1 edges
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> down(n + 1, 0);
  int ans = 0;

  auto dfs = [&](auto &&self, int root, int parent) -> void {
    int best1 = 0, best2 = 0;
    for (int next : adj[root]) {
      if (parent == next)
        continue;

      // ! Post order
      self(self, next, root);

      int len = down[next] + 1;
      if (len > best1) {
        best2 = best1;
        best1 = len;
      } else if (len > best2) {
        best2 = len;
      }
    }

    down[root] = best1;
    ans = std::max(ans, best1 + best2);
  };

  dfs(dfs, 1, 0);

  std::cout << ans << "\n";
  return 0;
}