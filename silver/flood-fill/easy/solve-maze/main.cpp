

// * https://codeforces.com/contest/1365/problem/D
// ? Flood-Fill, Ad-hoc

#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> matrix(n, std::vector<char>(m));
    int Gs = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        std::cin >> c;
        if (c == 'G')
          ++Gs;
        matrix[i][j] = c;
      }
    }

    int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
    bool failed = false;

    for (int i = 0; i < n && !failed; ++i) {
      for (int j = 0; j < m && !failed; ++j) {
        char cur = matrix[i][j];

        if (cur == 'B') {
          for (int d = 0; d < 4; ++d) { // ! Init d
            int ni = i + dir[0][d];
            int nj = j + dir[1][d];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
              continue;
            }

            if (matrix[ni][nj] == 'G') {
              std::cout << "No\n";
              failed = true;
              break;
            }

            if (matrix[ni][nj] == '.') {
              matrix[ni][nj] = '#';
            }
          }
        }
      }
    }

    if (failed) // ! Skip if failed
      continue;

    int visited_G = 0;
    int visited_B = 0;
    std::queue<std::pair<int, int>> q;
    bool blocked = (matrix[n - 1][m - 1] == '#'); // ! Check blocked

    q.push({n - 1, m - 1});
    matrix[n - 1][m - 1] = -1; // Mark visited

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (int d = 0; d < 4; ++d) {
        int nr = cur.first + dir[0][d];
        int nc = cur.second + dir[1][d];

        if (nr < 0 || nc < 0 || nr >= n || nc >= m)
          continue;
        if (matrix[nr][nc] == '#' || matrix[nr][nc] == -1)
          continue;

        q.push({nr, nc});
        if (matrix[nr][nc] == 'G')
          ++visited_G;
        else if (matrix[nr][nc] == 'B')
          ++visited_B;

        matrix[nr][nc] = -1; // ! Mark later
      }
    }

    if (blocked)
      std::cout << ((Gs > 0) ? "No\n" : "Yes\n");
    else
      std::cout << ((visited_G == Gs && visited_B == 0) ? "Yes\n" : "No\n");
  }

  return 0;
}