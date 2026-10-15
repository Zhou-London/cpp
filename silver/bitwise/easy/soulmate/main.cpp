

// * https://usaco.org/index.php?page=viewproblem2&cpid=1182
// ? Bitwise

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int N;
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    long long A, B;
    std::cin >> A >> B;

    long long cur = A;
    int cost = 0;

    // * Compute candidate "down" point
    std::vector<std::pair<long long, int>> table;
    table.push_back({cur, cost});

    while (cur > 1) {
      if (cur % 2 != 0) {
        ++cur;
        ++cost;
      } else {
        cur /= 2;
        ++cost;
      }
      table.push_back({cur, cost});
    }

    long long ans = INT_MAX;

    // * Compute "up" cost
    for (auto &[x, c] : table) {
      if (x > B) // Should be minus or divided more
        continue;

      long long best_up = INT_MAX;
      int low_k_cnt = 0;
      for (int k = 0; k < 64; ++k) { // ! k := times of multiplying 2
        long long top = B >> k;

        if (top < x)
          break;

        // ! k must g 0 when counting low k
        if (k > 0 && (B >> (k - 1)) & 1)
          ++low_k_cnt;

        long long up = (top - x) + k + low_k_cnt;
        best_up = std::min(best_up, up);
      }

      // * Take minimal "down" + "up"
      ans = std::min(ans, c + best_up);
    }

    std::cout << ans << "\n";
  }

  return 0;
}