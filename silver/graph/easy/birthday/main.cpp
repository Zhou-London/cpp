

// * https://open.kattis.com/problems/birthday
// ?

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  while (true) {
    int p, c;
    std::cin >> p >> c;

    if (p == 0 && c == 0)
      break;

    std::vector<std::vector<std::pair<int, int>>> adj(105);
    std::vector<int> dfn(105);
    std::vector<int> low(105);
    int timer = 0;
    bool hasBridge = false;

    for (int i = 0; i < c; ++i) {
      int a, b;
      std::cin >> a >> b;

      adj[a].push_back({b, 2 * i});
      adj[b].push_back({a, 2 * i + 1});
    }

    // Tarjan
    auto dfs = [&](auto &&self, int u, int fromEdge) -> void {
      dfn[u] = ++timer;
      low[u] = dfn[u];

      for (auto [v, id] : adj[u]) {
        if ((id ^ 1) == fromEdge)
          continue; // It is the "From Edge", continue
        if (!dfn[v]) {
          self(self, v, id);
          low[u] = std::min(low[u], low[v]);
          // ! Wrong: hasBridge = low[v] > dfn[u];
          if (low[v] > dfn[u])
            hasBridge = true;
        } else {
          low[u] = std::min(low[u], dfn[v]);
        }
      }
    };

    int components = 0;
    for (int i = 0; i < p; ++i) {
      if (!dfn[i]) { // ! Use dfn to replace visited
        dfs(dfs, i, -1);
        ++components;
      }
    }

    if (hasBridge || components > 1)
      std::cout << "Yes\n";
    else
      std::cout << "No\n";
  }
  return 0;
}