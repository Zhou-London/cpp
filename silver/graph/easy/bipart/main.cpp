

// * https://codeforces.com/contest/862/problem/B
// ? BFS, Two coloring

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<bool> visited(n + 1, false);
  std::vector<int> colors(n + 1, -1); // Only 0 and 1

  long long cnt0 = 0; // Count of colors
  long long cnt1 = 0;

  // ! Start by 1
  for (int i = 1; i <= n; ++i) {
    if (visited[i])
      continue;

    std::queue<int> q;
    q.push(i);
    visited[i] = true;
    if (colors[i] == -1) {
      colors[i] = 0;
      ++cnt0;
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next : adj[cur]) {
        if (!visited[next]) {
          q.push(next);
          visited[next] = true;

          if (colors[cur] == 0) {
            ++cnt1;
            colors[next] = 1;
          } else {
            ++cnt0;
            colors[next] = 0;
          }
        }
      }
    }
  }

  // ! Consider overflow
  std::cout << cnt0 * cnt1 - (n - 1) << "\n";
  return 0;
}