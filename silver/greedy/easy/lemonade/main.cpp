

// * https://usaco.org/index.php?page=viewproblem2&cpid=835
// ! 1000
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<int> waits(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> waits[i];
  }

  std::sort(waits.begin(), waits.end(), std::greater<>());

  int count = 0;
  for (int i = 0; i < N; ++i) {
    if (waits[i] >= count) {
      ++count;
    }
  }

  std::cout << count << "\n";
  return 0;
}