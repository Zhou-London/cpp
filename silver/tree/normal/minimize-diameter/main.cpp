

// * https://codeforces.com/gym/104536/problem/F
// ? Tree, Diameter

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, m;
  std::cin >> n;
  std::vector<std::vector<int>> adj1(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj1[a].push_back(b);
    adj1[b].push_back(a);
  }

  std::cin >> m;
  std::vector<std::vector<int>> adj2(m + 1);
  for (int i = 0; i < m - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj2[a].push_back(b);
    adj2[b].push_back(a);
  }

  auto diameter = [](const std::vector<std::vector<int>> &adj, int n) {
    std::queue<int> q;
    std::vector<int> dist(n + 1, -1);
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next : adj[cur]) {
        if (dist[next] != -1)
          continue;
        dist[next] = dist[cur] + 1;
        q.push(next);
      }
    }

    int nodeA = std::max_element(dist.begin(), dist.end()) - dist.begin();
    std::vector<int> distA(n + 1, -1);
    distA[nodeA] = 0;
    q.push(nodeA);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next : adj[cur]) {
        if (distA[next] != -1)
          continue;
        distA[next] = distA[cur] + 1;
        q.push(next);
      }
    }

    return *std::max_element(distA.begin(), distA.end());
  };

  int d1 = diameter(adj1, n);
  int d2 = diameter(adj2, m);

  int ans = std::max(d1, std::max(d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1));
  std::cout << ans << "\n";
  return 0;
}