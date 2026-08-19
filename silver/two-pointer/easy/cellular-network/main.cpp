
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
  int n, m;
  std::cin >> n >> m;

  // ! Overflow
  std::vector<long long> cities(n);
  std::vector<long long> towers(m);

  for (int i = 0; i < n; ++i)
    std::cin >> cities[i];

  for (int i = 0; i < m; ++i)
    std::cin >> towers[i];

  long long ans = 0;
  int r = 0;

  for (int l = 0; l < n; ++l) {
    // ! Use while to find next r, or stay with current r
    while (r + 1 < m && std::abs(towers[r + 1] - cities[l]) <=
                            std::abs(towers[r] - cities[l]))
      ++r;

    ans = std::max(ans, std::abs(towers[r] - cities[l]));
  }

  std::cout << ans << "\n";
  return 0;
}