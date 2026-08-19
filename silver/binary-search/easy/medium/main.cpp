
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

// https://codeforces.com/contest/1201/problem/C

int main() {
  // freopen("medium.in", "r", stdin);
  // freopen("medium.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;

  std::vector<long long> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::sort(arr.begin(), arr.end());

  auto check = [&](int x) {
    int mid = (n - 1) / 2;

    long long needs = 0;
    for (int i = mid; i < n; ++i) {
      needs += std::max((long long)0, x - arr[i]);
    }

    return needs <= k;
  };

  long long lower = arr[(n - 1) / 2];
  long long upper = lower + k;

  while (lower < upper) {
    // ! Converges to right: (R - L + 1) / 2
    // ! Converges to left: (R - L) / 2
    long long mid = lower + (upper - lower + 1) / 2;

    if (check(mid)) {
      lower = mid; // ! When finish, lower is the answer
    } else {
      upper = mid - 1;
    }
  }

  std::cout << lower << "\n";
}