

// * https://cses.fi/problemset/task/1095
// ? Modular

#include <iostream>
int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;

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

    std::cout << power(a, b, 1'000'000'000 + 7) << "\n";
  }

  return 0;
}