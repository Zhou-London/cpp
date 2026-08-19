
#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
int main() {
  // freopen("everywhere.in", "r", stdin);
  // freopen("everywhere.out", "w", stdout);

  int n;
  std::string s;

  std::cin >> n >> s;

  std::unordered_map<char, int> hash;

  for (int i = 0; i < n; ++i) {
    hash.try_emplace(s[i], 1);
  }

  int ans = INT_MAX;
  std::unordered_map<char, int> h;

  int r = 0;
  h[s[0]]++;
  for (int l = 0; l < n; ++l) {
    // ! h[s[l]]++
    // ! Don't do this as right ptr already did this before

    while (r + 1 < n && h.size() != hash.size()) {
      ++r;
      h[s[r]]++;
    }

    if (h.size() == hash.size())
      ans = std::min(ans, r - l + 1);

    h[s[l]]--;
    if (h[s[l]] == 0)
      h.erase(s[l]);
  }

  std::cout << ans << "\n";
  return 0;
}