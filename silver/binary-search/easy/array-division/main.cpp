

// https://cses.fi/problemset/task/1085

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;

  std::vector<long long> input(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> input[i];
  }

  // ! Don't sort: std::sort(input.begin(), input.end());

  auto check = [&](const long long X) {
    int sets = 1;
    long long sum = input[0];

    // ! Greedy
    for (int i = 1; i < n; ++i) {
      if (sum + input[i] > X) {
        sum = input[i];
        ++sets;
      } else {
        sum += input[i];
      }
    }

    return sets <= k;
  };

  // ! lo is the max single elem. Hi is the total sum
  long long lower = *std::max_element(input.begin(), input.end());
  long long upper = std::accumulate(input.begin(), input.end(), 0LL);

  while (lower < upper) {
    long long mid = lower + (upper - lower) / 2;

    if (check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << upper << "\n";
  return 0;
}