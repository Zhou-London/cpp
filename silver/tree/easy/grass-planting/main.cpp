

// * https://usaco.org/index.php?page=viewproblem2&cpid=894
// ? Tree

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> adj(N + 1);

  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> colors(N + 1, 0);
  std::vector<int> parents(N + 1, 0); // ! Record parent

  std::queue<int> q;
  q.push(1);
  colors[1] = 1;
  int ans = 1;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int color = 1;
    for (int next : adj[cur]) {
      if (next == parents[cur])
        continue;

      // ! Skip 2 steps
      while (color == colors[cur] || color == colors[parents[cur]])
        ++color;

      colors[next] = color++;
      parents[next] = cur;
      ans = std::max(ans, colors[next]);

      q.push(next);
    }
  }

  std::cout << ans << "\n";
  return 0;
}