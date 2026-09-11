

// * https://usaco.org/index.php?page=viewproblem2&cpid=895
// ? Flood-Fill

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<std::vector<char>> matrix(N, std::vector<char>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  long long area = 0;
  long long perimeter = 0;

  int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (matrix[i][j] == '.' || matrix[i][j] == -1) // ! Mark visited to -1
        continue;

      long long cur_area = 0;
      long long cur_peri = 0;

      std::queue<std::pair<int, int>> q;
      q.push({i, j});
      matrix[i][j] = -1;
      ++cur_area;

      while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
          int nx = cur.first + dir[0][d];
          int ny = cur.second + dir[1][d]; // ! Note using second

          if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            ++cur_peri;
            continue;
          }
          if (matrix[nx][ny] == '.') {
            ++cur_peri;
            continue;
          }
          if (matrix[nx][ny] == -1)
            continue;

          q.push({nx, ny});
          matrix[nx][ny] = -1;
          ++cur_area;
        }
      }

      if (cur_area > area || (cur_area == area && cur_peri < perimeter)) {
        area = cur_area;
        perimeter = cur_peri;
      }
    }
  }

  std::cout << area << " " << perimeter << "\n";
  return 0;
}