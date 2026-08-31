

// * https://usaco.org/index.php?page=viewproblem2&cpid=944
// ? Graph, Connectivity, BFS

#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);

  int N, M;
  std::cin >> N >> M;

  struct Cow {
    int x;
    int y;
  };

  std::vector<Cow> cows(N + 1);
  std::vector<std::vector<int>> adj(N + 1);

  for (int i = 1; i <= N; ++i) {
    int x, y;
    std::cin >> x >> y;
    cows[i] = {x, y};
  }

  for (int i = 1; i <= M; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  long long ans = INT_MAX;

  std::vector<bool> visited(N + 1, false);
  for (int i = 1; i <= N; ++i) {
    if (visited[i])
      continue;

    int x1 = INT_MAX;
    int x2 = INT_MIN;
    int y1 = INT_MAX;
    int y2 = INT_MIN;

    // BFS
    std::queue<int> q;
    q.push(i);
    visited[i] = true;

    x1 = std::min(x1, cows[i].x);
    x2 = std::max(x2, cows[i].x);
    y1 = std::min(y1, cows[i].y);
    y2 = std::max(y2, cows[i].y);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next : adj[cur]) { // ! Pick the adj list of `cur`
        if (visited[next])
          continue;

        q.push(next);
        visited[next] = true;

        x1 = std::min(x1, cows[next].x);
        x2 = std::max(x2, cows[next].x);
        y1 = std::min(y1, cows[next].y);
        y2 = std::max(y2, cows[next].y);
      }
    }

    long long perimeter = 2LL * (std::abs(x2 - x1) + std::abs(y2 - y1));

    ans = std::min(ans, perimeter);
  }

  std::cout << ans << "\n";
  return 0;
}
