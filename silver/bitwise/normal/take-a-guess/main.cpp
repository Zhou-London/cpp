

// * https://codeforces.com/contest/1556/problem/D
// ? Bitwise

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
  int n, k;
  std::cin >> n >> k;

  auto Ops = [](std::string str) {
    std::cout << str << std::endl;
    int val;
    std::cin >> val;
    return val;
  };

  int s12 = Ops("and 1 2") + Ops("or 1 2");
  int s13 = Ops("and 1 3") + Ops("or 1 3");
  int s23 = Ops("and 2 3") + Ops("or 2 3");

  std::vector<int> nums(n + 1, 0);
  nums[1] = (s12 + s13 - s23) / 2;
  nums[2] = s12 - nums[1];
  nums[3] = s13 - nums[1];

  for (int i = 4; i <= n; ++i) {
    int s1n =
        Ops("and 1 " + std::to_string(i)) + Ops("or 1 " + std::to_string(i));

    int n_val = s1n - nums[1];
    nums[i] = n_val;
  }

  std::sort(nums.begin() + 1, nums.end()); // ! 1-indexed
  std::cout << "finish " << nums[k] << std::endl; // ! The format

  return 0;
}