
#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>
int main() {
  std::ifstream fin("mowing.in");
  std::ofstream fout("mowing.out");

  int N;
  fin >> N;

  // * Don't need a whole matrix. Use a lazy approach
  std::pair<int, int> curr{0, 0};
  std::map<std::pair<int, int>, int> timestamp;

  int t = 0;
  int min_gap = INT_MAX;

  for (int i = 0; i < N; ++i) {
    char dir;
    int step;
    fin >> dir >> step;

    while (step--) {
      auto [it, inserted] = timestamp.try_emplace(curr, t);

      if (!inserted) {
        int time_gap = t - it->second;
        min_gap = std::min(min_gap, time_gap);

        it->second = t;
      }

      ++t;
      if(dir == 'N') curr.second += 1;
      else if(dir == 'E') curr.first += 1;
      else if(dir == 'W') curr.first -= 1;
      else if(dir == 'S') curr.second -= 1;
    }
  }

  int res = min_gap == INT_MAX ? -1 : min_gap;

  fout << res << "\n";

  return 0;
}