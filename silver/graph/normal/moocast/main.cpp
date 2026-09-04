

// * https://usaco.org/index.php?page=viewproblem2&cpid=669
// ? Connectivity, BFS, Binary Search

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int N;
  std::cin >> N;

  struct Cow {
    int x;
    int y;
  };

  std::vector<Cow> cows(N + 1);

  for (int i = 0; i < N; ++i) {
    int x, y;
    std::cin >> x >> y;

    cows[i + 1] = {x, y}; // ! Indexing
  }

  auto Check = [&](long long money) {
    std::vector<bool> visited(N + 1, false);
    int components = 0;

    for (int i = 1; i <= N; ++i) {
      if (visited[i])
        continue;

      std::queue<int> q;
      q.push(i);
      visited[i] = true;

      ++components;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = 1; next <= N; ++next) {
          if (!visited[next]) {
            int x = (cows[cur].x - cows[next].x) * (cows[cur].x - cows[next].x);
            int y = (cows[cur].y - cows[next].y) * (cows[cur].y - cows[next].y);
            int dist = x + y; // ! Algebra
            if (dist <= money) {
              q.push(next);
              visited[next] = true;
            }
          }
        }
      }
    }
    return components == 1;
  };

  long long lower = 0;
  long long upper = 2LL * 25000 * 25000; // ! Overflow

  while (lower < upper) {
    long long mid = lower + (upper - lower) / 2;

    if (Check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << upper << "\n";
  return 0;
}
