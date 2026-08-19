
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
int main() {
  std::ifstream fin("censor.in");
  std::ofstream fout("censor.out");

  std::string S;
  std::string T;

  fin >> S >> T;

  // * Build failure function
  std::vector<int> failure(T.size());
  for (int i = 1; i < failure.size(); ++i) {
    int j = failure[i - 1];
    while (j > 0 && T[j] != T[i])
      j = failure[j - 1];

    if (T[j] == T[i])
      ++j;
    failure[i] = j;
  }

  // * Build DFA
  auto Shift = [&T, &S, &failure](int i, int state) -> int {
    const char c = S[i];

    while (state > 0 && T[state] != c) {
      state = failure[state - 1];
    }

    if (T[state] == c)
      ++state;

    return state;
  };

  // Iterate
  struct Rec {
    char c;
    int state;
  };

  std::vector<Rec> stk;

  int state = 0;
  for (int i = 0; i < S.size(); ++i) {
    state = Shift(i, state);
    stk.push_back({S[i], state});

    if (state == T.size()) {
      for (int j = 0; j < T.size(); ++j) {
        stk.pop_back();
      }
      state = stk.back().state;
    }
  }

  std::string ans = "";
  for(const auto& r : stk)
    ans += r.c;

  fout << ans << "\n";

  return 0;
}