

// * https://usaco.org/index.php?page=viewproblem2&cpid=788
// ? Tree

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);

  int N, Q;
  std::cin >> N >> Q;

  struct Video {
    int id;
    int relevance;
  };

  std::vector<std::vector<Video>> adj(N + 1);
  for (int i = 1; i <= N - 1; ++i) {
    int p, q, r;
    std::cin >> p >> q >> r;

    adj[p].push_back({q, r});
    adj[q].push_back({p, r});
  }

  auto Query = [&](int v, int k) {
    std::vector<bool> visited(N + 1, false); // ! visited is not really necessary
    std::queue<int> q;
    q.push(v);
    visited[v] = true;
    int vis_cnt = 0;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto &next : adj[cur]) {
        if (!visited[next.id] && next.relevance >= k) {
          q.push(next.id);
          visited[next.id] = true;
          ++vis_cnt;
        }
      }
    }

    return vis_cnt;
  };

  for (int i = 0; i < Q; ++i) {
    int k, v;
    std::cin >> k >> v;
    std::cout << Query(v, k) << "\n";
  }

  return 0;
}