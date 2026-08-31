

// * https://open.kattis.com/problems/birthday
// ?

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  while (true) {
    int p, c;
    std::cin >> p >> c;

    if (p == 0 && c == 0)
      break;

    std::vector<std::vector<int>> adj(p);
    for (int i = 0; i < p; ++i) {
      int a, b;
      std::cin >> a >> b;

      adj[a].push_back(b);
      adj[b].push_back(a);
    }

  }
  return 0;
}