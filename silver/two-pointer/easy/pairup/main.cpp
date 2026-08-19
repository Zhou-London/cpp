
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>
int main() {
  std::ifstream fin("pairup.in");
  std::ofstream fout("pairup.out");

  int N;
  fin >> N;

  std::vector<std::pair<int, int>> vec(N);

  for (int i = 0; i < N; ++i) {
    int count, milk;
    fin >> count >> milk;

    vec[i] = {milk, count};
  }

  std::sort(vec.begin(), vec.end());

  int l = 0;
  int r = N - 1;

  int ans = 0;

  while (l < r) {
    // * Think about "Skip"
    // * If you can trade at once, don't trade one by one
    int volume = std::min(vec[l].second, vec[r].second);
    int sum = vec[l].first + vec[r].first;
    ans = std::max(ans, sum);

    vec[l].second -= volume;
    vec[r].second -= volume;

    if (!vec[l].second)
      ++l;
    if (!vec[r].second)
      --r;
  }

  fout << ans << "\n";
  return 0;
}