

// * https://cses.fi/problemset/task/1727
// ? Exp

#include <cmath>
#include <cstdio>
#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  // * P(M) := Prob that M is the maximum numbers of candies
  // * E(M) = 1 * P(M=1) + 2 * P(M=2) + ...
  // * P(M) = m^n - (m - 1)^n   /
  // *        k^n

  double result = 0.0;
  for (int m = 1; m <= k; ++m) {
    double mkb = (double)m / k;
    double m1kb = (double)(m - 1) / k;

    double mk = 1.0; // ! From 1
    double m1k = 1.0;

    for (int i = 0; i < n; ++i) {
      mk *= mkb;
      m1k *= m1kb;
    }

    result += m * (mk - m1k);
  }

  // * Round half to even at 6 decimals, done by hand:
  // * an exact tie like 9.1919575 is stored slightly below, so printf rounds it down
  double v = result * 1e6;
  long long f = (long long)std::floor(v);
  double d = v - f;

  long long q;
  if (std::fabs(d - 0.5) < 1e-6) {
    q = (f % 2 == 0) ? f : f + 1; // tie -> even
  } else if (d < 0.5) {
    q = f;
  } else {
    q = f + 1;
  }

  std::printf("%lld.%06lld\n", q / 1000000, q % 1000000);
  return 0;
}