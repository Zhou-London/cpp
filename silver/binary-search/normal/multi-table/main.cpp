
// * https://cses.fi/problemset/task/2422
// ? Binary search, mathematics, count

#include <algorithm>
#include <cstdio>
#include <iostream>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  long long n; // ! Overflow if int
  std::cin >> n;

  long long k = (n * n + 1) / 2; // ! 0-based

  // * Func return: Number of values that is not bigger than val
  // * Works because the n^2 array is static. The mallest count that works is definitely the correct index
  auto Check = [&](const long long val) {
    long long count = 0;
    for (int r = 1; r <= n; ++r) {
      count += std::min(val / r, n);
    }

    return count >= k; // count := 0-based index, make the index smallest
  };

  long long lower = 0;
  long long upper = n * n;

  while (lower < upper) {
    long long mid = lower + (upper - lower) / 2;

    if (Check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << upper << "\n";
}