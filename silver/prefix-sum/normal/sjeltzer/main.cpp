
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
int main() {
  int N;
  std::cin >> N;

  std::vector<long long> P(1000000, 0);

  for (int i = 0; i < N; ++i) {
    std::string id;
    int size;

    std::cin >> id >> size;
    P[std::stoi(id)] = size;
  }

  auto getDigit = [](int n, int dim) { return n / dim % 10; };

  // Build 6D Prefix Sum
  // dim = 10 ^ 0 -> 10 ^ 5
  int dim = 1;
  while (dim < 1000000) {
    for (int i = 0; i < 1000000; ++i) {
      if (getDigit(i, dim) >= 1) {
        P[i] += P[i - dim];
      }
    }

    dim *= 10;
  }

  auto getBit = [](int mask, int k) { return (mask >> k) & 1; };

  // Define query
  auto Query = [&](const std::string &x, const std::string &y) -> long long {
    long long ans = 0;

    // Inc-Exc in dim6
    for (int mask = 0; mask < 64; ++mask) {
      int x_num = 0;
      int idx = 0;
      bool valid = true;
      int power = 100000;

      // bit = 0 -> Take y, bit = 1 -> take x - 1
      for (int k = 0; k < 6; ++k) {
        int digit;

        // ! Check bit (defensive)
        if(x[k] > y[k]) return 0;

        if (getBit(mask, k)) {
          ++x_num;
          digit = x[k] - '0' - 1;
        } else {
          digit = y[k] - '0';
        }

        if (digit < 0) {
          valid = false;
          break;
        }

        idx += power * digit;
        power /= 10;
      }

      // ! x_num % 2 == 0 (false) -> 1
      if (valid)
        ans += ((x_num % 2) ? -1 : 1) * P[idx];
    }

    return ans;
  };

  int Q;
  std::cin >> Q;

  for (int i = 0; i < Q; ++i) {
    std::string x;
    std::string y;

    std::cin >> x >> y;

    std::cout << Query(x, y) << "\n";
  }

  return 0;
}