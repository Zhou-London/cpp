
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main() {
  using ll = long long;

  std::ifstream fin("cowtip.in");
  std::ofstream fout("cowtip.out");

  ll N;
  fin >> N;

  std::vector<ll> matrix(N * N);

  for (ll i = 0; i < N; ++i) {
    std::string s;
    fin >> s;

    for (ll j = 0; j < N; ++j) {
      matrix[j + i * N] = s[j] - '0';
    }
  }

  auto loc = [&](ll r, ll c) -> ll & { return matrix[c + r * N]; };
  auto flip = [&](ll r, ll c) {
    for (ll i = 0; i <= r; ++i) {
      for (ll j = 0; j <= c; ++j) {
        auto &val = matrix[j + i * N];

        val = val == 0 ? 1 : 0;
      }
    }
  };

  int count = 0;

  while (true) {
    // Locate the "pivot"
    ll p_r = 0;
    ll p_c = 0;

    bool located = false;

    for (ll i = N - 1; i >= 0; --i) {
      for (ll j = N - 1; j >= 0; --j) {
        if (loc(i, j) == 1) {
          p_r = i;
          p_c = j;
          located = true;
          break;
        }
      }

      if (located)
        break;
    }

    // All 0
    if (!located) {
      break;
    }

    // Flip using pivot
    flip(p_r, p_c);

    ++count;
  }

  fout << count;

  return 0;
}