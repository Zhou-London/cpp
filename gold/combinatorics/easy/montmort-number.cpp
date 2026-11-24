

// * https://judge.yosupo.jp/problem/montmort_number_mod
// ? Modular, Perm

#include <iostream>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<long long> an(N + 2);
  an[1] = 0;
  an[2] = 1 % M;
  for (int i = 3; i <= N; ++i) {
    an[i] = (i - 1) * ((an[i - 2] + an[i - 1]) % M) % M;
  }

  for (int i = 1; i <= N; ++i) {
    std::cout << an[i] << "\n";
  }

  return 0;
}