

// * https://usaco.org/index.php?page=viewproblem2&cpid=644
// ? Graph, Connectivity

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> closes(N + 1); // The order that barn closes
  for (int i = 1; i <= N; ++i) {
    int b;
    std::cin >> b;
    closes[i] = b;
  }

  std::vector<bool> open(N + 1, true); // is i-th barn open

  for (int i = 1; i <= N; ++i) {
    // * Count connected components
    std::vector<bool> visited(N + 1, false);
    int count = 0;

    for (int s = 1; s <= N; ++s) {
      if (!open[s] || visited[s])
        continue;
      ++count;

      std::queue<int> q;
      q.push(s);
      visited[s] = true;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
          if (!open[next] || visited[next])
            continue;

          visited[next] = true;
          q.push(next);
        }
      }
    }

    if (count == 1)
      std::cout << "YES\n";

    else
      std::cout << "NO\n";

    // Close
    open[closes[i]] = false;
  }
}