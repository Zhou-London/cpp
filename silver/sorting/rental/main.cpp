

// * https://usaco.org/index.php?page=viewproblem2&cpid=787
// ? Prefix sum, Suffix sum, 2 Pointer

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  int N, M, R;
  std::cin >> N >> M >> R;

  std::vector<int> milks(N);
  std::vector<std::pair<int, int>> shops(M);
  std::vector<int> rents(R);

  for (int i = 0; i < N; ++i) {
    std::cin >> milks[i];
  }
  std::sort(milks.begin(), milks.end(), std::greater<>());

  for (int i = 0; i < M; ++i) {
    int qty, price;
    std::cin >> qty >> price;

    shops[i] = {price, qty}; // ! Already resized
  }
  std::sort(shops.begin(), shops.end(), std::greater<>());

  for (int i = 0; i < R; ++i) {
    std::cin >> rents[i];
  }
  std::sort(rents.begin(), rents.end(), std::greater<>());

  std::vector<long long> psum_milk(N + 1, 0); // inclusive
  std::vector<long long> ssum_rent(N + 1, 0); // exclusive

  // Build psum_milk
  int shop_idx = 0; // ! 2-Pointer

  for (int i = 0; i < N; ++i) {
    int left_milk = milks[i];
    long long value = 0;

    while (left_milk > 0 && shop_idx < M) {
      auto &shop = shops[shop_idx];

      long long qty = std::min(left_milk, shop.second);
      value += qty * shop.first; // ! Overflow

      left_milk -= qty;
      shop.second -= qty; // ! Minus the shop

      if (shop.second == 0)
        ++shop_idx;
    }

    psum_milk[i + 1] = psum_milk[i] + value;
  }

  // Build ssum_rent
  for (int i = N - 1; i >= 0; --i) {
    int idx = N - i - 1;
    if (idx < R) // ! < R
      ssum_rent[i] = ssum_rent[i + 1] + rents[idx];
    else
      ssum_rent[i] = ssum_rent[i + 1];
  }

  auto Query = [&](int k) { return psum_milk[k] + ssum_rent[k]; };

  long long ans = 0;
  for (int i = 0; i <= N; ++i)
    ans = std::max(ans, Query(i));

  std::cout << ans << "\n";
  return 0;
}