

// * https://usaco.org/index.php?page=viewproblem2&cpid=968
// ? Tree, Connectivity, Multi-coloring

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);

  int N, M;
  std::cin >> N >> M;

  std::vector<char> genes(N + 1);
  for (int i = 1; i <= N; ++i) {
    std::cin >> genes[i];
  }

  std::vector<std::vector<int>> adj(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // ! Bi-direct
  }

  std::vector<int> comps(N + 1, 0);
  int cnt = 0;

  for (int i = 1; i <= N; ++i) {
    if (comps[i] == 0) {
      ++cnt;
      std::queue<int> q;
      q.push(i);
      comps[i] = cnt;

      while (!q.empty()) { // ! q.empty
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
          if (comps[next] == 0 && genes[next] == genes[cur]) {
            q.push(next);
            comps[next] = cnt;
          }
        }
      }
    }
  }

  std::string ans;
  for (int i = 0; i < M; ++i) {
    int u, v;
    char p;
    std::cin >> u >> v >> p;

    if (comps[u] != comps[v]) {
      ans += '1';
    } else if (genes[u] == p) {
      ans += '1';
    } else {
      ans += '0';
    }
  }

  std::cout << ans << "\n";
  return 0;
}