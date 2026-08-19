
#include <algorithm>
#include <fstream>
#include <iostream>
#include <linux/limits.h>
#include <vector>
int main() {
  std::ifstream fin("diamond.in");
  std::ofstream fout("diamond.out");

  int N, K;
  fin >> N >> K;

  std::vector<int> input(N);

  for (int i = 0; i < N; ++i) {
    fin >> input[i];
  }

  std::sort(input.begin(), input.end());

  // For each index i, the maximum length
  std::vector<int> len(N);

  // ! 2 pointer
  int r = 0;
  for (int l = 0; l < N; ++l) {
    if (r < l)
      r = l;

    while (r + 1 < N && input[r + 1] - input[l] <= K)
      ++r;

    len[l] = r - l + 1;
  }

  // ! Right max
  std::vector<int> best_right(N);
  best_right[N - 1] = len[N - 1];

  for (int i = N - 2; i >= 0; --i) {
    best_right[i] = std::max(best_right[i + 1], len[i]);
  }

  // ! Left max
  std::vector<int> best_left(N);

  for (int i = 0; i < N; ++i) {
    int end = i + len[i] - 1;
    best_left[end] = std::max(best_left[end], len[i]);
  }

  for (int i = 1; i < N; ++i) {
    best_left[i] = std::max(best_left[i], best_left[i - 1]);
  }

  // ! Search the "split"
  int ans = 0;
  for (int i = 0; i + 1 < N; ++i) {
    ans = std::max(ans, best_left[i] + best_right[i + 1]);
  }

  fout << ans << "\n";

  return 0;
}