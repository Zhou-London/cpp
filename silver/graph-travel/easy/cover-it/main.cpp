

// * https://codeforces.com/problemset/problem/1176/E
// ? BFS, Two coloring
// ! 1700

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
      int v, u;
      std::cin >> v >> u;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    std::queue<int> q;
    std::vector<bool> visited(n + 1, false);
    std::vector<int> deps(n + 1, 0);

    std::vector<int> even;
    std::vector<int> odd;

    q.push(1);
    visited[1] = true;
    deps[1] = 0;
    even.push_back(1);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto &next : adj[cur]) {
        if (!visited[next]) {
          q.push(next);
          deps[next] = deps[cur] + 1;
          visited[next] = true;

          if (deps[next] % 2 == 0)
            even.push_back(next);
          else
            odd.push_back(next);
        }
      }
    }

    if (even.size() <= odd.size()) {
      std::cout << even.size() << "\n";
      for (auto &v : even)
        std::cout << v << " ";
    } else {
      std::cout << odd.size() << "\n";
      for (auto &v : odd)
        std::cout << v << " ";
    }

    std::cout << "\n";
  }

  return 0;
}