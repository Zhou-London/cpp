#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
int main() {
  std::ifstream fin("cbarn.in");
  std::ofstream fout("cbarn.out");

  int n;
  fin >> n;

  std::vector<int> rooms(n);
  for(int i = 0; i < n; ++i){
    fin >> rooms[i];
  }

  auto next = [&](int idx){
    if(idx < n - 1){
        return idx + 1;
    }

    return 0;
  };

  int min = INT_MAX;
  for(int i = 0; i < n; ++i){
    int step = 1;
    int next_i = next(i);
    int dist = 0;

    while(next_i != i){
        dist += step++ * rooms[next_i];

        next_i = next(next_i);
    }

    min = std::min(dist, min);
  }

  fout << min << "\n";
}