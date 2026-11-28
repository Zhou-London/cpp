

// * https://atcoder.jp/contests/dp/tasks/dp_a
// ? DP (Pull)

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> heights(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> heights[i];
  }

  std::vector<int> dp(N, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i < N; ++i) {
    for (int k = 1; k <= 2; ++k) {
      if (i - k >= 0) {
        dp[i] =
            std::min(dp[i], dp[i - k] + std::abs(heights[i] - heights[i - k]));
      }
    }
  }

  std::cout << dp[N - 1] << "\n";
  return 0;
}