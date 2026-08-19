
#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

int main(){

    std::ifstream fin("factory.in");
    std::ofstream fout("factory.out");

    int N;
    fin >> N;

    // Reversed adjacent list
    std::vector<std::vector<int>> radj(N + 1);
    std::vector<bool> visited(N + 1);

    for(int i = 0; i < N - 1; ++i){
        int a,b;
        fin >> a >> b;

        radj[b].push_back(a);
    }

    auto dfs = [&](auto&& self, int u) -> void {
        visited[u] = true;
        for(int v : radj[u])
            if(!visited[v]) self(self, v);
    };

    for(int i = 1; i <= N; ++i){
        visited.assign(N + 1, false);
        dfs(dfs, i);
    
        bool ok = true;
        for(int j = 1; j <= N; ++j){
            if(!visited[j]){
                ok = false;
                break;
            }
        }

        if(ok){
            fout << i << "\n";
            return 0;
        }
    }

    fout << -1 << "\n";
    return 0;
}