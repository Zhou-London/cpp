
#include <fstream>
#include <vector>
int main() {
  std::ifstream fin("coin.in");
  std::ofstream fout("coin.out");

  int n;
  fin >> n;

  std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
  std::vector<int> res;

  int curr = 0;
  while (curr < n) {
    for (int idx = 7; idx >= 0; --idx) {
      if (curr + coins[idx] <= n) {
        curr += coins[idx];
        res.push_back(coins[idx]);

        break;
      }
    }

    if (curr == n) {
      break;
    }
  }

  for (const auto &i : res) {
    fout << i << "\n";
  }

  return 0;
}