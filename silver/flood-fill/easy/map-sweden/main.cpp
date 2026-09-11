

// * https://open.kattis.com/problems/sverigekartan
// ? Flood-fill

#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int R, C, U;
  std::cin >> R >> C >> U;

  std::vector<std::vector<char>> matrix(R, std::vector<char>(C));
  std::pair<int, int> storm;

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      char c;
      std::cin >> c;
      if (c == 'S')
        storm = {i, j};

      matrix[i][j] = c;
    }
  }

  int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

  auto BFS = [&]() {
    std::vector<std::vector<bool>> visited(R, std::vector<bool>(C, false));
    std::queue<std::pair<int, int>> q;
    q.push(storm);
    visited[storm.first][storm.second] = true;

    long long lands = 1;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (int d = 0; d < 4; ++d) {
        int nr = cur.first + dir[0][d];
        int nc = cur.second + dir[1][d];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
          continue;
        if (visited[nr][nc] || matrix[nr][nc] == '.')
          continue;

        q.push({nr, nc});
        ++lands;
        visited[nr][nc] = true;
      }
    }

    return lands;
  };

  std::cout << BFS() << "\n";

  for (int i = 0; i < U; ++i) {
    int r, c;
    std::cin >> r >> c;
    matrix[r - 1][c - 1] = '#';

    std::cout << BFS() << "\n";
  }

  return 0;
}