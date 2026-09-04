

// * https://usaco.org/index.php?page=viewproblem2&cpid=992
// ? Connectivity, BFS, Binary Search, Sorting

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);

  int N, M;
  std::cin >> N >> M;

  bool sorted = true;
  std::vector<int> cows(N + 1);
  std::vector<int> subgraph;
  for (int i = 1; i <= N; ++i) {
    std::cin >> cows[i];

    if (cows[i] != i) {
      sorted = false;
      subgraph.push_back(cows[i]);
    }
  }

  if (sorted) {
    std::cout << "-1\n";
    return 0;
  }

  struct Wormhole {
    int a;
    int b;
    int w;
  };

  std::vector<Wormhole> holes(M);
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    std::cin >> a >> b >> w;
    holes[i] = {a, b, w};
  }

  std::sort(holes.begin(), holes.end(),
            [](const Wormhole &i, const Wormhole &j) { return i.w < j.w; });

  int S = subgraph.size();
  auto Check = [&](int least_w) {
    // std::unordered_map<int, std::vector<int>> adj;
    std::vector<std::vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
      auto &hole = holes[i];
      if (hole.w >= least_w) {
        adj[hole.a].push_back(hole.b);
        adj[hole.b].push_back(hole.a);
      }
    }

    int components = 0;

    // std::unordered_map<int, bool> visited;
    std::vector<bool> visited(N + 1, false); // vector is faster by 30% in this case

    for (int p : subgraph) {
      if (visited[p])
        continue;

      if (components > 0)
        return false;

      std::queue<int> q;
      q.push(p);
      visited[p] = true;

      ++components;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
          if (!visited[next]) {
            q.push(next);
            visited[next] = true;
          }
        }
      }
    }

    return components == 1;
  };

  int lower = holes[0].w;
  int upper = holes[M - 1].w;

  while (lower < upper) {
    int mid = lower + (upper - lower + 1) / 2;

    if (Check(mid)) {
      lower = mid;
    } else {
      upper = mid - 1;
    }
  }

  std::cout << lower << "\n";
  return 0;
}