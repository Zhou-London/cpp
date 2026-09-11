

// * https://cses.fi/problemset/task/1666
// ? Graph, BFS, Connectivity

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

  std::vector<bool> visited(n + 1, false);
  std::vector<int> reps;

  for (int i = 1; i <= n; ++i) {
    if (visited[i])
      continue;

    reps.push_back(i);

    std::queue<int> q;
    visited[i] = true;
    q.push(i);
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int node : adj[f]) {
        if (!visited[node]) {
          visited[node] = true;
          q.push(node);
        }
      }
    }
  }

  std::cout << reps.size() - 1 << "\n";
  for (int i = 1; i < reps.size(); ++i) {
    std::cout << reps[0] << " " << reps[i] << "\n";
  }

  return 0;
}