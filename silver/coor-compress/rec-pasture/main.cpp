
// * https://usaco.org/index.php?page=viewproblem2&cpid=1063
// ? 2D Psum, Coord Compress, Mathematics

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int N;
  std::cin >> N;

  using Point = std::pair<int, int>;
  std::vector<Point> points(N);

  for (auto &[x, y] : points)
    std::cin >> x >> y;

  // Coord Compress
  std::sort(points.begin(), points.end());
  for (int i = 0; i < N; ++i)
    points[i].first = i + 1;

  std::sort(points.begin(), points.end(),
            [](Point &a, Point &b) { return a.second < b.second; });
  for (int i = 0; i < N; ++i)
    points[i].second = i + 1;

  // 0: No cow, 1: Cow
  std::vector<std::vector<int>> matrix(N + 1, std::vector<int>(N + 1, 0));
  for (const auto &p : points)
    matrix[p.first][p.second] = 1;

  // psum[i][j]: Number of cows from O to (i, j)
  std::vector<std::vector<int>> psum(N + 1, std::vector<int>(N + 1, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      psum[i + 1][j + 1] =
          psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + matrix[i + 1][j + 1];
    }
  }

  auto Query = [&](int x1, int y1, int x2, int y2) -> long long {
    return psum[x2][y2] - psum[x1][y2] - psum[x2][y1] + psum[x1][y1];
  };

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      int y1 = i;
      int y2 = j + 1; // ! offset by 1
      int x1 = std::min(points[i].first, points[j].first);
      int x2 = std::max(points[i].first, points[j].first);

      long long left = Query(0, y1, x1, y2);
      long long right = Query(x2 - 1, y1, N, y2); // ! Include the x2
      ans += left * right;
    }
  }

  std::cout << ans + 1 << "\n"; // ! Plus one for empty set
  return 0;
}