#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string s;
vector<string> perms;
int char_count[26];

void search(const string &curr = "") {
  // We've finished creating a permutation
  if (curr.size() == s.size()) {
    perms.push_back(curr);
    return;
  }
  for (int i = 0; i < 26; i++) {
    // For all available characters
    if (char_count[i] > 0) {
      // Add it to the current string and continue the search
      char_count[i]--;
      search(curr + (char)('a' + i));
      char_count[i]++;
    }
  }
}

int main() {
  ifstream fin("strings.in");
  ofstream fout("strings.out");
  fin >> s;
  for (char c : s) {
    char_count[c - 'a']++;
  }

  search();

  fout << perms.size() << '\n';
  for (const string &perm : perms) {
    fout << perm << '\n';
  }
}