

// * https://cses.fi/problemset/task/1079
// ? Modular, comb

#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;

  constexpr int N = 1'000'000;
  constexpr int p = 1'000'000'000 + 7;
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

  std::vector<long long> fact(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact[i] = fact[i - 1] * i % p;
  }

  std::vector<long long> fact_inv(N + 1);
  fact_inv[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact_inv[i] = power(fact[i], p - 2, p);
  }

  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;

    std::cout << ((fact[a] * fact_inv[b] % p) * fact_inv[a - b] % p) << "\n";
  }

  return 0;
}