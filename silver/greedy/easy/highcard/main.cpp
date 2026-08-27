

// * https://usaco.org/index.php?page=viewproblem2&cpid=571
// ? Greedy, 2 Pointer
// ! 1500

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<int> occured(2 * N + 1);
  std::vector<int> bessie;
  std::vector<int> elsie;

  for (int i = 0; i < N; ++i) {
    int card;
    std::cin >> card;

    elsie.push_back(card);
    occured[card] = 1;
  }

  for (int i = 1; i <= 2 * N; ++i) {
    if (!occured[i])
      bessie.push_back(i);
  }

  std::sort(bessie.begin(), bessie.end());
  std::sort(elsie.begin(), elsie.end());

  int l = 0;
  long long ans = 0;
  for (int r = 0; r < N; ++r) {
    while (l + 1 < N && bessie[l] < elsie[r])
      ++l;

    if (bessie[l] >= elsie[r]) {
      ++l; // ! Update left pointer
      ++ans;
    } else {
      break;
    }
  }

  std::cout << ans << "\n";
  return 0;
}