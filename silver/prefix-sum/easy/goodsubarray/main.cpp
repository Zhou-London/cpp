
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
int main() {
    auto &fin = std::cin;
    auto &fout = std::cout;

//   std::ifstream fin("good.in");
//   std::ofstream fout("good.out");

  int t;
  fin >> t;
  while (t--) {
    // Handle input
    int n;
    fin >> n;

    std::string str;
    fin >> str;

    std::vector<int> vec(n, 0);
    for (int i = 0; i < str.size(); ++i) {
      vec[i] = str[i] - '0';
    }

    // Prefix sum
    std::vector<int> psum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      psum[i + 1] = psum[i] + vec[i];
    }

    // Search ans
    long long ans = 0;
    std::unordered_map<int, long long> map;
    for (int r = 0; r <= n; ++r) {
      // r - (l - 1) = psum[r] - psum[l - 1]
      // psum[r] - r = psum[l - 1] - (l - 1)
      map[psum[r] - r]++;
    }

    // Evaluate how many "clash" in total
    for(auto& [_, cnt] : map){
        ans += cnt * (cnt - 1) / 2;
    }

    fout << ans << "\n";
  }

  return 0;
}