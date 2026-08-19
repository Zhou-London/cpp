

#include <fstream>
#include <vector>
int main() { 
    
    std::ifstream fin("gymnastics.in");
    std::ofstream fout("gymnastics.out");

    int K, N;
    fin >> K >> N;

    std::vector<std::vector<int>> rank(K, std::vector<int>(N));
    for(int i = 0; i < K; ++i){
        for(int j = 0; j < N; ++j){
            int cow;
            fin >> cow;

            rank[i][cow] = j; // smaller is better
        }
    }

    int res = 0;

    // Search all pairs of a and b
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;

            bool consis = true;
            for(int s = 0; s < K; ++s){
                if(!(rank[s][i] < rank[s][j])){
                   consis = false;
                   break; 
                }
            }

            if(consis) res++;
        }
    }

    fout << res << "\n";

    return 0; 
}