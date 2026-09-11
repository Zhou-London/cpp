

// * https://cses.fi/problemset/task/1192
// ? Flood-Fill, BFS, Connectivity

#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<char>> matrix(n, std::vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  int dir_x[4] = {1, -1, 0, 0};
  int dir_y[4] = {0, 0, 1, -1};

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == -1 || matrix[i][j] == '#')
        continue;

      ++ans;

      std::queue<std::pair<int, int>> q;
      matrix[i][j] = -1; // Mark visited
      q.push({i, j});

      while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
          int next_x = cur.first + dir_x[d];
          int next_y = cur.second + dir_y[d];

          if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
            continue;
          if (matrix[next_x][next_y] == -1 || matrix[next_x][next_y] == '#')
            continue;

          matrix[next_x][next_y] = -1;
          q.push({next_x, next_y});
        }
      }
    }
  }

  std::cout << ans << "\n";
  return 0;
}