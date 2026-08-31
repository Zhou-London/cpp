

// * https://usaco.org/index.php?page=viewproblem2&cpid=668
// ? Graph, BFS, Connectivity

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <endian.h>
#include <iostream>
#include <queue>

#include <vector>
int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int N;
  std::cin >> N;

  struct Cow {
    int x = 0;
    int y = 0;
    int r = 0;
  };

  std::vector<Cow> cows(N);
  for (int i = 0; i < N; ++i) {
    int x, y, r;
    std::cin >> x >> y >> r;

    cows[i] = {x, y, r};
  }

  // ! Euclidean distance
  auto reachable = [&](Cow &a, Cow &b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;

    return dx * dx + dy * dy <= (long long)a.r * a.r; // ! Depends on a's radius
  };

  int ans = 0;

  for (int i = 0; i < N; ++i) {
    std::vector<bool> visited(N, false); // ! New visited vector each time, because the graph is directed
    std::queue<int> q;
    visited[i] = true;
    q.push(i);

    int count = 1; // ! Init to 1

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next = 0; next < N; ++next) {
        if (visited[next])
          continue;

        if (reachable(cows[cur], cows[next])) {
          ++count;
          visited[next] = true;
          q.push(next);
        }
      }
    }

    ans = std::max(ans, count);
  }

  std::cout << ans << "\n";
  return 0;
}