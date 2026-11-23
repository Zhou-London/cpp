

// * https://cses.fi/problemset/task/1712
// ? Modular

#include <iostream>
int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;

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

    long long mod_num = 1'000'000'000 + 7;

    long long e = power(b, c, mod_num - 1);

    std::cout << power(a, e, mod_num) << "\n";
  }

  return 0;
}