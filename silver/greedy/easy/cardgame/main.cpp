

// * https://usaco.org/index.php?page=viewproblem2&cpid=573
// ? Greedy, Sorting, Divide and Conquer
// ! 1900

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
int main() {
  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<int> occured(2 * N + 1);

  std::vector<int> bessie;
  std::vector<int> elsie;
  for (int i = 0; i < N; ++i) {
    int card;
    std::cin >> card;

    occured[card] = 1;
    elsie.push_back(card);
  }

  for (int i = 1; i <= 2 * N; ++i) {
    if (!occured[i])
      bessie.push_back(i);
  }

  int M = N / 2;

  // ! First half is global Dsc
  // ! Second half is then Asc
  std::sort(bessie.begin(), bessie.end(), std::greater<>()); // ! [A,B)
  std::sort(bessie.begin(), bessie.begin() + M);

  std::sort(elsie.begin(), elsie.begin() + M);
  std::sort(elsie.begin() + M, elsie.end(), std::greater<>());

  int l = 0;
  long long ans = 0;
  for (int r = 0; r < M; ++r) {
    while (l + 1 < M && bessie[l] < elsie[r])
      ++l;

    if (l != M && bessie[l] >= elsie[r]) {
      ++l; // ! Update left pointer
      ++ans;
    } else {
      break;
    }
  }

  l = M;
  for (int r = M; r < N; ++r) {
    while (l + 1 < N && bessie[l] > elsie[r])
      ++l;

    if (l != N && bessie[l] <= elsie[r]) {
      ++l; // ! Update left pointer
      ++ans;
    } else {
      break;
    }
  }

  std::cout << ans << "\n";
  return 0;
}