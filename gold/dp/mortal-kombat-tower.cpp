

// * https://codeforces.com/problemset/problem/1418/C
// ? DP

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;

    std::vector<int> bosses(n + 1);
    for (int i = 1; i <= n; ++i) {
      std::cin >> bosses[i];
    }

    // * dp[i][p] := Til ith boss, next turn is p, by then the min skip points
    // ! 1-indexed
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 1e9));

    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
      // ! Check bound
      if (i + 1 <= n) {
        dp[i + 1][1] = std::min(dp[i + 1][1], dp[i][0] + bosses[i + 1]);
        dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][1]);
      }

      if (i + 2 <= n) {
        dp[i + 2][1] =
            std::min(dp[i + 2][1], dp[i][0] + bosses[i + 1] + bosses[i + 2]);
        dp[i + 2][0] = std::min(dp[i + 2][0], dp[i][1]);
      }
    }

    std::cout << std::min(dp[n][0], dp[n][1]) << "\n";
  }

  return 0;
}