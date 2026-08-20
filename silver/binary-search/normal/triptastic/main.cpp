

// * https://www.codechef.com/problems/TRPTSTIC
// ? Binary search + 2D Prefix sum

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  int T;
  std::cin >> T;

  while (T--) {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<long long>> matrix(N, std::vector<long long>(M, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        std::cin >> matrix[i][j];
      }
    }

    // Build 2D psum
    std::vector<std::vector<long long>> psum(N + 1,
                                             std::vector<long long>(M + 1, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        psum[i + 1][j + 1] =
            psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + matrix[i][j];
      }
    }

    // ! Count the mentor
    if (psum[N][M] < K + 1) {
      std::cout << -1 << " \n";
      continue;
    }

    auto Query = [&](const int r1, const int c1, const int r2, const int c2) {
      return psum[r2][c2] - psum[r1][c2] - psum[r2][c1] + psum[r1][c1];
    };

    // Binary search func
    auto Check = [&](const int D) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (matrix[i][j] == 0)
            continue; // ! Mentor can't fit in
          int r1 = std::max(0, i - D), c1 = std::max(0, j - D);
          int r2 = std::min(N - 1, i + D), c2 = std::min(M - 1, j + D);
          if (Query(r1, c1, r2 + 1, c2 + 1) >= K + 1) // ! Exclusive
            return true;
        }
      }
      return false;
    };

    long long lower = 0;
    long long upper = N + M;

    // ! Direction
    while (lower < upper) {
      long long mid = lower + (upper - lower) / 2;

      if (Check(mid)) {
        upper = mid;
      } else {
        lower = mid + 1;
      }
    }

    std::cout << upper << "\n";
  }
}