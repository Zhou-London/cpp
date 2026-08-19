
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
int main(){

    std::ifstream fin("whereami.in");
    std::ofstream fout("whereami.out");

    int N;
    fin >> N;

    std::string str;
    fin >> str;

    // Iterate each substring of size k
    for(int k = 1; k <= N; ++k){
        std::unordered_set<std::string> set;

        bool duplicated = false;
        for(int i = 0; i + k <= N; ++i){
            const auto& sub = str.substr(i, k);

            if(set.find(sub) != set.end())
                duplicated = true;
            set.insert(sub);
        }

        // Check duplication
        if(!duplicated){
            fout << k << "\n";
            return 0;
        }
    }

    return 1;
}