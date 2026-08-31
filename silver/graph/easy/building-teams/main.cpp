

// * https://cses.fi/problemset/task/1668
// ? Graph, BFS, Two-coloring

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> colors(n + 1, 0); // 1 -> Team 1, 2 -> Team 2
  for (int i = 1; i <= n; ++i) {
    if (colors[i] != 0)
      continue;

    std::queue<int> q;
    q.push(i);
    colors[i] = 1;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next : adj[cur]) {
        if (colors[next] == 0) {
          colors[next] = colors[cur] == 1 ? 2 : 1; // Assign to different teams
          q.push(next);
        } else if (colors[next] == colors[cur]) {
          std::cout << "IMPOSSIBLE\n";
          return 0;
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << colors[i] << "\n";
  }

  std::cout << "\n";

  return 0;
}