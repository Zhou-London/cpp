

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
int main(){

    std::ifstream fin("kayaking.in");
    std::ofstream fout("kayaking.out");

    int n;
    fin >> n;

    std::vector<int> vec(2 * n);
    for(int i = 0; i < n * 2; ++i)
        fin >> vec[i];

    std::sort(vec.begin(), vec.end());

    std::vector<int> diff;
    for(int i = 0; i < 2 * n - 1; i += 2){
        diff.push_back(vec[i + 1] - vec[i]);
    }

    std::sort(diff.begin(), diff.end());

    int res = 0;
    for(int i = 0; i < n - 1; ++i)
        res += diff[i];

    fout << res;

    return 0;
}