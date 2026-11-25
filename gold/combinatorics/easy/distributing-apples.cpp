

// * https://cses.fi/problemset/task/1716
// ? Stars and Bars

#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  long long p = 1'000'000'000 + 7;
  auto power = [](long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
      if (exp & 1)
        result = result * base % mod;
      base = base * base % mod;
      exp >>= 1;
    }

    return result;
  };

  int N = 1'000'000;
  std::vector<long long> fact(2 * N + 1); // ! or (n + m)
  fact[0] = 1;
  for (int i = 1; i <= 2 * N; ++i) { // ! Update the range as above
    fact[i] = fact[i - 1] * i % p;
  }

  auto comb = [&](long long a, long long b) {
    auto result = (fact[a] * power(fact[b], p - 2, p) % p) *
                  power(fact[a - b], p - 2, p) % p;
    return result;
  };

  std::cout << comb(m + n - 1, n - 1) << "\n";
  return 0;
}