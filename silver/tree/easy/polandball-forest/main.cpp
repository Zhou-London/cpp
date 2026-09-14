

// * https://codeforces.com/contest/755/problem/C
// ? Tree, Connectivity, Ad-hoc

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<int> balls(n + 1);
  for (int i = 1; i <= n; ++i)
    std::cin >> balls[i];

  int single_cnt = 0;
  int diff_cnt = 0;

  std::set<int> set;
  for (int i = 1; i <= n; ++i) {
    if (i == balls[i])
      ++single_cnt;

    set.insert(balls[i]);
  }

  diff_cnt = set.size(); // ! Use set

  std::cout << single_cnt + (diff_cnt - single_cnt) / 2 << "\n";
}