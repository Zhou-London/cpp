
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
int main(){
    std::ifstream fin("notlast.in");
    std::ofstream fout("notlast.out");

    int N;
    fin >> N;

    std::unordered_map<std::string, int> map;
    for(int i = 0; i < N; ++i){
        std::string cow;
        int milk;
        fin >> cow >> milk;

        map[cow] += milk;
    }

    std::vector<std::pair<int, std::string>> vec;

    for(const auto& [cow, milk] : map){
        vec.push_back({milk, cow});
    }

    std::sort(vec.begin(), vec.end());

    int idx = 0;
    if(vec.size() == 7){
        int smallest = vec[0].first;

        // Count from the second one
        idx = 1;
        while(idx < vec.size() && vec[idx].first == smallest)
            ++idx;
    } // Else, idx is 0, considering the 0 milk cow are not in the vector

    if(idx < vec.size() &&
    (idx + 1 == vec.size() || vec[idx].first != vec[idx+1].first)){
        fout << vec[idx].second << "\n";
    } else {
        fout << "Tie\n";
    }

    return 0;
}