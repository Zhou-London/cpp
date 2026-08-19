
#include <algorithm>
#include <fstream>
#include <vector>
int main() {
  std::ifstream fin("haybales.in");
  std::ofstream fout("haybales.out");

  int N, Q;
  fin >> N >> Q;

  std::vector<long long> input(N);
  for (int i = 0; i < N; ++i)
    fin >> input[i];

  std::sort(input.begin(), input.end());

  for (int i = 0; i < Q; ++i) {
    int l, r;
    fin >> l >> r;

    auto lit = std::lower_bound(input.begin(), input.end(), l);
    auto rit = std::upper_bound(input.begin(), input.end(), r);

    fout << rit - lit << "\n";
  }

  return 0;
}