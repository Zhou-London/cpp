
#include <algorithm>
#include <climits>
#include <fstream>
#include <unordered_map>
#include <vector>
int main() {
  std::ifstream fin("div7.in");
  std::ofstream fout("div7.out");

  int N;
  fin >> N;

  std::vector<long long> psum(N + 1, 0);
  for (int i = 0; i < N; ++i) {
    int n;
    fin >> n;

    psum[i + 1] = psum[i] + n;
  }

  std::unordered_map<long long, long long> map;

  // * (S[j] - S[i]) mod 7 == 0
  // * -> S[j] mod 7 == S[i] mod 7
  // * A bit greedy?
  long long ans = LLONG_MIN;
  for (int i = 0; i <= N; ++i) {
    auto it = map.find(psum[i] % 7);
    if (it != map.end()) {
      long long len = i - it->second;
      ans = std::max(ans, len);
    } else {
      map[psum[i] % 7] = i;
    }
  }

  fout << ans << "\n";
  return 0;
}