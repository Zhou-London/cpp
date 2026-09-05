

// * https://usaco.org/index.php?page=viewproblem2&cpid=1304
// ? Bellman-Ford, BFS, Sorting, Two Pointer

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int N, M;
  std::cin >> N >> M;

  struct Flight {
    int r;
    int d;
    int s;
  };

  std::vector<std::vector<Flight>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    int c, r, d, s;
    std::cin >> c >> r >> d >> s;

    adj[c].push_back({r, d, s});
  }

  for (int i = 1; i <= N; ++i) {
    std::sort(
        adj[i].begin(), adj[i].end(),
        [](const Flight &a, const Flight &b) { return a.r > b.r; }); // ! Dsc
  }

  std::vector<int> a(N + 1);
  for (int i = 1; i <= N; ++i) {
    std::cin >> a[i];
  }

  std::vector<long long> dist(N + 1, LLONG_MAX);
  dist[1] = 0;

  std::vector<bool> inq(N + 1, false);
  std::vector<int> ptr(N + 1, 0); // ! Two Pointer methods

  std::queue<int> q;
  q.push(1);
  inq[1] = true;
  bool first = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    inq[cur] = false;

    long long threshold;
    if (first) {
      first = false;
      threshold = 0;
    } else {
      threshold = dist[cur] + a[cur];
    }

    while (ptr[cur] < (int)adj[cur].size() &&
           adj[cur][ptr[cur]].r >= threshold) {
      auto &next = adj[cur][ptr[cur]];
      ++ptr[cur]; // Move the ptr to reduce cost

      if (next.s < dist[next.d]) {
        dist[next.d] = next.s; // Update min time

        if (!inq[next.d]) {
          q.push(next.d);
          inq[next.d] = true;
        }
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (dist[i] == LLONG_MAX)
      std::cout << -1 << "\n";
    else
      std::cout << dist[i] << "\n";
  }

  return 0;
}