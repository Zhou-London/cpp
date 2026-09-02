

// * https://usaco.org/index.php?page=viewproblem2&cpid=920
// ? BFS, Two coloring

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);

  int N, M;
  std::cin >> N >> M;

  struct Edge {
    int type;
    int dest;
  };

  std::vector<std::vector<Edge>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    char t;
    int a, b;

    std::cin >> t >> a >> b;
    adj[a].push_back({t, b});
    adj[b].push_back({t, a});
  }

  std::vector<int> colors(N + 1, -1);
  std::vector<bool> visited(N + 1, false);

  int components = 0;

  for (int i = 1; i <= N; ++i) {
    if (visited[i])
      continue;

    ++components;

    std::queue<int> q;
    q.push(i);
    colors[i] = 0;
    visited[i] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto &next : adj[cur]) {
        int want = next.type == 'S' ? colors[cur] : colors[cur] ^ 1;

        if (colors[next.dest] == -1) {
          colors[next.dest] = want;
        } else if (colors[next.dest] == want) {
          continue;
        } else {
          std::cout << "0\n";
          return 0;
        }

        visited[next.dest] = true;
        q.push(next.dest);
      }
    }
  }

  // ! Answer = 2 ^ k
  // ! But you can not represent this number when k is 50000, even with LL
  std::cout << "1";
  for (int i = 0; i < components; ++i)
    std::cout << "0";

  std::cout << "\n";
  return 0;
}