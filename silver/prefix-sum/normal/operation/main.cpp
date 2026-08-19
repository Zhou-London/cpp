
#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  // std::ifstream fin("operation.in");
  // std::ofstream fout("operation.out");

  auto& fin = std::cin;
  auto& fout = std::cout;

  int T;
  fin >> T;

  while (T--) {
    int N, M;
    fin >> N >> M;

    // * Preprocess a: mod M and sort
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      fin >> a[i];
      a[i] %= M;
    }

    std::sort(a.begin(), a.end());

    // Construct b: {a - M, a, a + M}
    std::vector<int> b(3 * N);
    for (int i = 0; i < N; ++i) {
      b[i] = a[i] - M;
    }

    for (int i = 0; i < N; ++i) {
      b[i + N] = a[i];
    }

    for (int i = 0; i < N; ++i) {
      b[i + N * 2] = a[i] + M;
    }

    // Process prefix sum
    std::vector<long long> psum(3 * N + 1); // * Use long long
    for (int i = 0; i < 3 * N; ++i) {
      psum[i + 1] = psum[i] + b[i];
    }

    long long min_cost = LLONG_MAX;
    int offset = (N - 1) / 2;

    // For each index j as the median number
    for (int j = N; j < 2 * N; ++j) {
      int l = j - offset;
      int r = l + N - 1;
      long long median = b[j];

      long long left_cost = (j - l + 1) * median - (long long)(psum[j + 1] - psum[l]);
      long long right_cost = (long long)(psum[r + 1] - psum[j + 1]) - (r - j) * median;

      min_cost = std::min(left_cost + right_cost, min_cost);
    }

    fout << min_cost << "\n";
  }

  return 0;
}