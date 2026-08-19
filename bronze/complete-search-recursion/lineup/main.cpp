

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
int main() {

  std::ifstream fin("lineup.in");
  std::ofstream fout("lineup.out");

  int N;
  fin >> N;

  std::vector<std::string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                                   "Bella",  "Blue",      "Betsy",   "Sue"};
  std::sort(cows.begin(), cows.end());

  std::vector<std::pair<std::string, std::string>> rules;
  for (int i = 0; i < N; ++i) {
    std::string cowA;
    std::string cowB;

    fin >> cowA;

    for (int skip = 0; skip < 4; ++skip)
      fin >> cowB;

    fin >> cowB;

    rules.push_back({cowA, cowB});
  }

  // Find element location
  auto loc = [&](const std::string &cow) {
    return std::find(cows.begin(), cows.end(), cow) - cows.begin();
  };

  std::vector<std::vector<std::string>> res;

  do {
    // * Check availability
    bool ok = true;
    for (const auto &rule : rules) {
      auto locA = loc(rule.first);
      auto locB = loc(rule.second);

      if (std::abs(locA - locB) > 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      res.push_back(cows);
    }
  } while (std::next_permutation(cows.begin(), cows.end()));

  for (const auto &s : res[0]) {
    fout << s << "\n";
  }

  return 0;
}