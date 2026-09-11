

// * https://open.kattis.com/problems/sverigekartan
// ? DSU

#include <iostream>
#include <utility>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int R, C, U;
  std::cin >> R >> C >> U;

  std::vector<std::vector<char>> matrix(R, std::vector<char>(C));

  int storm = -1;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      std::cin >> matrix[i][j];
      if (matrix[i][j] == 'S')
        storm = i * C + j;
    }
  }

  int n = R * C;
  std::vector<int> parent(n);
  std::vector<int> size(n, 1);

  auto Find = [&](auto &&self, int x) -> int {
    if (parent[x] == x)
      return x;
    return parent[x] = self(self, parent[x]);
  };

  auto Unite = [&](int a, int b) {
    a = Find(Find, a);
    b = Find(Find, b);

    if (a == b)
      return;
    if (size[a] < size[b])
      std::swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  };

  for (int i = 0; i < n; ++i)
    parent[i] = i;

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (matrix[i][j] == '.')
        continue;
      if (i + 1 < R && matrix[i + 1][j] != '.') { // ! Check right and down
        Unite(i * C + j, (i + 1) * C + j);
      }
      if (j + 1 < C && matrix[i][j + 1] != '.') {
        Unite(i * C + j, i * C + j + 1);
      }
    }
  }

  std::cout << size[Find(Find, storm)] << "\n";

  int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
  for (int i = 0; i < U; ++i) {
    int r, c;
    std::cin >> r >> c;

    --r;
    --c;

    if (matrix[r][c] == '.') {
      matrix[r][c] = '#';
      for (int d = 0; d < 4; ++d) {
        int nr = r + dir[0][d];
        int nc = c + dir[1][d];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
          continue;

        if (matrix[nr][nc] != '.')
          Unite(r * C + c, nr * C + nc);
      }
    }

    std::cout << size[Find(Find, storm)] << "\n";
  }

  return 0;
}