

// https://usaco.org/index.php?page=viewproblem2&cpid=690

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("cowdance.in", "r", stdin);
  freopen("cowdance.out", "w", stdout);

  int N, T;
  std::cin >> N >> T;

  std::vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    std::cin >> arr[i];

  auto check = [&](const int x) {
    // ! Use priority queue to simulate
    std::priority_queue<long long, std::vector<long long>,
                        std::greater<long long>>
        pq;

    long long total = 0;

    for (int i = 0; i < x; ++i) {
      pq.push(arr[i]);
      total = std::max<long long>(
          total, arr[i]); // ! The slowest is current total time
    }

    for (int i = x; i < N; ++i) {
      long long t = pq.top(); // The "Quickest" one
      pq.pop();

      long long finish =
          t +
          arr[i]; // The quickest plus the new time -> The new potential total
      pq.push(finish);

      total = std::max(total, finish); // ! Update the total time
    }

    // Check if time is enough
    return total <= T;
  };

  long long lower = 1;
  long long upper = N - 1;

  while (lower < upper) {
    // ! Converges to right: (R - L + 1) / 2
    // ! Converges to left: (R - L) / 2, OK
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