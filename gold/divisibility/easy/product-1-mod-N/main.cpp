

// * https://codeforces.com/problemset/problem/1514/C
// ? Divisibility, Prime numbers

#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> primes;
  long long mul = 1;
  for (int i = 1; i <= n; ++i) {
    if (std::gcd(i, n) == 1) { // ! >= C++ 17
      primes.push_back(i);
      mul = mul * i % n; // ! Overflow trick
    }
  }

  if (mul % n == 1) {
    std::cout << primes.size() << "\n";
    for (int p : primes)
      std::cout << p << " ";
  } else {
    std::cout << primes.size() - 1 << "\n";
    for (int p : primes)
      if (p != mul % n)
        std::cout << p << " ";
  }

  std::cout << "\n";

  return 0;
}