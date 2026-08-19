

#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::ifstream fin("shell.in");
  std::ofstream fout("shell.out");

  int N;
  fin >> N;

  std::vector<int> pebble_at{1, 2, 3};
  std::vector<int> guess_count{0, 0, 0};

  for (int i = 0; i < N; ++i) {
    int a, b, g;
    fin >> a >> b >> g;

    --a;
    --b;
    --g;

    std::swap(pebble_at[a], pebble_at[b]);
    ++guess_count[pebble_at[g] - 1];
  }

  fout << std::max({guess_count[0], guess_count[1], guess_count[2]});
}