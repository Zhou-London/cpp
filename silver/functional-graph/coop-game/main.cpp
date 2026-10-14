

// * https://codeforces.com/contest/1137/problem/D
// ? Functional Graph, Floyd's Algorithm

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
int main() {
  int k;

  auto readGroups = [&]() {
    std::cin >> k;
    std::vector<int> g(10);
    for (int i = 0; i < k; ++i) {
      std::string s;
      std::cin >> s;

      if (s == "stop")
        exit(0);
      for (char c : s)
        g[c - '0'] = i;
    }

    return g;
  };

  while (true) {
    std::cout << "next 0 1" << std::endl;
    readGroups();
    std::cout << "next 0" << std::endl;
    auto g = readGroups();
    if (g[0] == g[1])
      break;
  }

  while (true) {
    std::cout << "next 0 1 2 3 4 5 6 7 8 9" << std::endl;
    readGroups();
    if (k == 1)
      break;
  }

  std::cout << "done" << std::endl;
  return 0;
}