

// * https://www.spoj.com/problems/ETF/
// ? Divisibility

#include <iostream>
#include <utility>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    long long result = n;

    // * Factorization
    std::vector<std::pair<long long, long long>> factors;

    for (long long p = 2; p <= n / p; ++p) {
      if (n % p == 0) {
        int cnt = 0;

        while (n % p == 0) {
          n /= p;
          ++cnt;
        }

        factors.push_back({p, cnt});
      }
    }

    if (n > 1) {
      factors.push_back({n, 1});
    }

    for (auto &[factor, cnt] : factors) {
      result -= result / factor;
    }

    std::cout << result << "\n";
  }

  return 0;
}