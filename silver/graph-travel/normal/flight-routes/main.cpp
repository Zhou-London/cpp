

// * https://cses.fi/problemset/task/1682
// ? Connectivity, Strong connected componenets

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n + 1);
  std::vector<std::vector<int>> radj(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;

    adj[a].push_back(b);
    radj[b].push_back(a);
  }

  std::vector<bool> visited(n + 1, false);
  // Fix 1, and check connectivity
  // First round
  std::queue<int> q;
  q.push(1);
  visited[1] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : adj[cur]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      std::cout << "NO\n";
      std::cout << 1 << " " << i << "\n";
      return 0;
    }
  }

  // Second round
  visited.assign(n + 1, false); // ! Use assign
  q.push(1);
  visited[1] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : radj[cur]) { // * Reverse
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      std::cout << "NO\n";
      std::cout << i << " " << 1 << "\n"; // ! Consider the direction
      return 0;
    }
  }

  std::cout << "YES\n";
  return 0;
}