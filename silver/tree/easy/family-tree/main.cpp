

// * https://usaco.org/index.php?page=viewproblem2&cpid=833
// ? Tree, Map, Ad-hoc

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>

int main() {
  freopen("family.in", "r", stdin);
  freopen("family.out", "w", stdout);

  int N;
  std::cin >> N;
  std::string A, B;
  int a = -1;
  int b = -1;
  std::cin >> A >> B;

  std::map<std::string, std::string> mother;
  for (int i = 0; i < N; ++i) {
    std::string m, c;
    std::cin >> m >> c;

    mother[c] = m;
  }

  std::map<std::string, int> distA;
  int dist = 0;
  for (std::string cur = A; !cur.empty(); cur = mother[cur]) {
    distA[cur] = dist;
    ++dist;
  }

  dist = 0;
  for (std::string cur = B; !cur.empty(); cur = mother[cur]) {
    auto it = distA.find(cur);
    if (it != distA.end()) {
      a = it->second;
      b = dist;
      break; // ! Break
    }
    ++dist;
  }

  if (a > b) {
    std::swap(a, b);
    std::swap(A, B);
  }

  if (a == -1 && b == -1) {
    std::cout << "NOT RELATED\n";
  } else if (a == 1 && b == 1) {
    std::cout << "SIBLINGS\n";
  } else if (a == 0) {
    std::string ans;
    if (b == 1)
      ans = "mother";

    if (b >= 2) {
      for (int i = 0; i < b - 2; ++i)
        ans += "great-";
      ans += "grand-mother";
    }
    std::cout << A << " is the " << ans << " of " << B << "\n";
  } else if (a == 1 && b >= 2) {
    std::string ans;
    for (int i = 0; i < b - 2; ++i)
      ans += "great-";
    ans += "aunt";
    std::cout << A << " is the " << ans << " of " << B << "\n";
  } else {
    std::cout << "COUSINS\n";
  }

  return 0;
}