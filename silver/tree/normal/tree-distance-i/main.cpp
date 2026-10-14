

// * https://cses.fi/problemset/task/1132/
// ? Tree, Diameter

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // * Find diameter point a
  std::vector<int> dist1(n + 1, -1);
  std::queue<int> q;
  q.push(1);
  dist1[1] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : adj[cur]) {
      if (dist1[next] != -1) {
        continue;
      }

      dist1[next] = dist1[cur] + 1;
      q.push(next);
    }
  }
  int a = std::max_element(dist1.begin(), dist1.end()) - dist1.begin();

  // * Find diameter point b
  std::vector<int> distA(n + 1, -1);
  q.push(a);
  distA[a] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : adj[cur]) {
      if (distA[next] != -1) {
        continue;
      }
      distA[next] = distA[cur] + 1;
      q.push(next);
    }
  }
  int b = std::max_element(distA.begin(), distA.end()) - distA.begin();

  // * Compute distB
  std::vector<int> distB(n + 1, -1);
  q.push(b);
  distB[b] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : adj[cur]) {
      if (distB[next] != -1) {
        continue;
      }
      distB[next] = distB[cur] + 1;
      q.push(next);
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << std::max(distA[i], distB[i]) << " ";
  }

  std::cout << "\n";
  return 0;
}