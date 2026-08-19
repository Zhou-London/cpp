
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
int main() {
  std::ifstream fin("hps.in");
  std::ofstream fout("hps.out");

  int N;
  fin >> N;

  // * psum[i][G] -> Til i, how many games can gesture G win
  // H:0, P:1, S:2
  std::vector<std::vector<long long>> psum(N + 1, std::vector<long long>(3, 0));

  // Evaluate prefix sum
  for (int i = 0; i < N; ++i) {
    char G;
    fin >> G;

    psum[i + 1][0] = psum[i][0];
    psum[i + 1][1] = psum[i][1];
    psum[i + 1][2] = psum[i][2];

    if (G == 'H')
      ++psum[i + 1][1];
    else if (G == 'P')
      ++psum[i + 1][2];
    else
      ++psum[i + 1][0];
  }

  // Search maximum
  long long max = INT_MIN;

  for (int i = 0; i <= N; ++i) {
    for (int a = 0; a < 3; ++a) {
      for (int b = 0; b < 3; ++b) {
        max = std::max(max, psum[i][a] + psum[N][b] - psum[i][b]);
      }
    }
  }

  fout << max;

  return 0;
}