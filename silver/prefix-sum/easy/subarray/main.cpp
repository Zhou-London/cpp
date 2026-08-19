
#include <algorithm>
#include <climits>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  //   std::ifstream fin("subarray.in");
  //   std::ofstream fout("subarray.out");

  auto &fin = std::cin;
  auto &fout = std::cout;

  int N;
  fin >> N;

  std::vector<long long> psum(N + 1);

  for (int i = 0; i < N; ++i) {
    int n;
    fin >> n;

    psum[i + 1] = psum[i] + n;
  }

  long long curr_min = psum[0];
  long long ans = LLONG_MIN;

  // ! The order matters
  for (int i = 1; i <= N; ++i) {
    long long sum = psum[i] - curr_min;
    ans = std::max(sum, ans);

    curr_min = std::min(psum[i], curr_min);
  }

  fout << ans << "\n";
  return 0;
}