

// * https://codeforces.com/contest/1279/problem/D
// ? Statistics, Modular, Fermat's LT

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> wants(n);
  std::vector<int> item_cnts(1'000'000 + 1);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;

    wants[i].resize(k);
    for (int j = 0; j < k; ++j) {
      int item;
      std::cin >> item;
      wants[i][j] = item;

      item_cnts[item]++;
    }
  }

  constexpr int p = 998244353;
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

  // ! Modular trick
  long long ans = 0;
  for (int kid = 0; kid < n; ++kid) {
    long long s = 0;
    for (int item : wants[kid])
      s += item_cnts[item];

    long long inv_k = power(wants[kid].size(), p - 2, p);
    ans = (ans + (s % p) * inv_k) % p;
  }

  long long inv_n = power(n, p - 2, p);
  ans = ((ans * inv_n) % p * inv_n) % p;

  std::cout << ans << "\n";
  return 0;
}