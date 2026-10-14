

// * https://cses.fi/problemset/task/1133
// ? Tree, DP

#include <iostream>
#include <queue>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) { // ! n-1 edges on tree
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<long long> sz(n + 1, 1);
  long long ans1 = 0;
  auto dfs = [&](auto &&self, int root, int parent, int depth) -> void {
    ans1 += depth;
    for (int next : adj[root]) {
      if (next == parent) // ! Use parent to check
        continue;

      self(self, next, root, depth + 1);
      sz[root] += sz[next]; // ! Compute sub-tree size
    }
  };
  dfs(dfs, 1, 0, 0);

  // Imply the ans for children
  std::queue<int> q;
  std::vector<long long> ans(n + 1, 0);
  ans[1] = ans1;
  q.push(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : adj[cur]) {
      if (ans[next])
        continue;
      ans[next] = ans[cur] + n - 2 * sz[next];
      q.push(next);
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << ans[i] << " ";
  }

  std::cout << "\n";
  return 0;
}