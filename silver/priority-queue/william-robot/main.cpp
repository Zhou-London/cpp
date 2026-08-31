

// * https://codeforces.com/gym/104002/problem/E
// ? Priority Queue, Greedy, Mathematics

#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  for (int i = 0; i < n; ++i) {
    int limit = (i + 2) / 2;

    pq.push(numbers[i]);
    while (pq.size() > limit) {
      pq.pop();
    }
  }

  long long ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  std::cout << ans << "\n";
  return 0;
}