
// https://codeforces.com/contest/1520/problem/F1

#include <cstdio>
#include <iostream>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, t, k;
  std::cin >> n >> t >> k;

  int lower = 1, upper = n;
  while (lower < upper) { // ! Condition is lower < upper
    int mid = lower + (upper - lower) / 2;

    std::cout << "? " << 1 << " " << mid << std::endl;

    int s;
    std::cin >> s;

    if (s == -1)
      return 1;

    int zeros = mid - s; // Number of all symbols - Number of 1

    if (zeros >= k)
      upper = mid;
    else
      lower = mid + 1;
  }

  // ! Follow the rules
  std::cout << "! " << upper << std::endl;
  return 0;
}
