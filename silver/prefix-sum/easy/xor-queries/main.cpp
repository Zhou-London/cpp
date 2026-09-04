

// * https://cses.fi/problemset/task/1650
// ? Prefix sum

#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, q;
  std::cin >> n >> q;

  std::vector<long long> arr(n, 0);
  std::vector<long long> psum(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    psum[i] = psum[i - 1] ^ arr[i - 1]; // ! ^ with the original array
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    std::cin >> a >> b;

    std::cout << (psum[b] ^ psum[a - 1]) << "\n";
  }

  return 0;
}