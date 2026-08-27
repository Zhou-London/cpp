

// * https://codeforces.com/contest/321/problem/B
// ? Greedy, Sorting, Divide and conquer
// ! 1900

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
int main() {

  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  struct Card {
    std::string type;
    int strength;
  };

  std::vector<Card> jiro(n);
  for (int i = 0; i < n; ++i) {
    std::string t;
    int s;
    std::cin >> t >> s;

    jiro[i] = {t, s};
  }

  std::vector<int> ciel(m);
  for (int i = 0; i < m; ++i) {
    int s;
    std::cin >> s;

    ciel[i] = s;
  }

  std::sort(ciel.begin(), ciel.end(), std::greater<>());
  std::sort(jiro.begin(), jiro.end(),
            [](Card &a, Card &b) { return a.strength < b.strength; });

  // * Strategy 1: All in attack
  int ci = 0;
  long long ans1 = 0;
  for (int ji = 0; ji < n && ci < m; ++ji) {
    if (jiro[ji].type == "DEF") // Skip all DEF card
      continue;

    while (ci + 1 < m && ciel[ci] < jiro[ji].strength)
      ++ci;

    if (ciel[ci] >= jiro[ji].strength) {
      ans1 += ciel[ci] - jiro[ji].strength;
      ++ci;
    }
  }

  // * Strategy 2: Destroy everything and attack directly
  long long ans2 = 0;

  std::vector<bool> cused(m, false);
  bool no_card = true; // * If Jiro lose all his cards

  // 2.1 Destroy all DEF
  std::sort(ciel.begin(), ciel.end());// Sort ciel Asc

  ci = 0;
  for (int ji = 0; ji < n; ++ji) {
    if (jiro[ji].type == "ATK")
      continue;

    while (ci + 1 < m && ciel[ci] <= jiro[ji].strength)
      ++ci;

    // ! Check ci < m here
    if (ci < m && ciel[ci] > jiro[ji].strength) {
      cused[ci] = true;
      ++ci;
    } else {
      no_card = false;
      break;
    }
  }

  // 2.2 Destroy all ATK
  ci = 0;
  for (int ji = 0; ji < n; ++ji) {
    if (jiro[ji].type == "DEF")
      continue;

    while ((ci + 1 < m && ciel[ci] < jiro[ji].strength) || cused[ci])
      ++ci;

    if (ci < m && ciel[ci] >= jiro[ji].strength) {
      ans2 += ciel[ci] - jiro[ji].strength;
      cused[ci] = true;
      ++ci;
    } else {
      no_card = false;
      break;
    }
  }

  if (no_card) {
    for (int i = 0; i < m; ++i)
      if (!cused[i])
        ans2 += ciel[i];
  } else {
    ans2 = 0;
  }

  std::cout << std::max(ans1, ans2) << "\n";

  return 0;
}