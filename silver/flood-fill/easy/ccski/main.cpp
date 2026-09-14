

// * https://usaco.org/index.php?page=viewproblem2&cpid=380
// ?

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main() {
  freopen("ccski.in", "r", stdin);
  freopen("ccski.out", "w", stdout);

  int M, N;
  std::cin >> M >> N;

  std::vector<std::vector<int>> heights(M, std::vector<int>(N, 0));
  std::vector<std::vector<int>> waypoints(M, std::vector<int>(N, 0));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> heights[i][j];
    }
  }

  int waypoints_cnt = 0;
  int wi;
  int wj;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int n;
      std::cin >> n;
      if (n == 1) {
        ++waypoints_cnt;
        wi = i;
        wj = j;
      }
      waypoints[i][j] = n;
    }
  }

  int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

  auto Check = [&](int k) {
    std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));
    int visited_cnt = 0;

    std::queue<std::pair<int, int>> q;
    q.push({wi, wj});
    visited[wi][wj] = true;
    ++visited_cnt;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (int d = 0; d < 4; ++d) {
        int ni = cur.first + dir[0][d];
        int nj = cur.second + dir[1][d];

        if (ni < 0 || ni >= M || nj < 0 || nj >= N)
          continue;
        if (visited[ni][nj] ||
            std::abs(heights[cur.first][cur.second] - heights[ni][nj]) > k)
          continue;

        q.push({ni, nj});
        visited[ni][nj] = true;
        if (waypoints[ni][nj])
          ++visited_cnt;
      }
    }

    return visited_cnt == waypoints_cnt;
  };

  int lower = 0;
  int upper = 1e9;

  while (lower < upper) {
    int mid = lower + (upper - lower) / 2;
    if (Check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << upper << "\n";
  return 0;
}