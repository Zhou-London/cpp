
#include <algorithm>
#include <fstream>
#include <vector>
int main(){
    std::ifstream fin("casino.in");
    std::ofstream fout("casino.out");

    int t;
    fin >> t;

    for(int T = 0; T < t; ++T){
        int n, m;

        fin >> n >> m;

        std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
        for(int a = 0; a < n; ++a){
            for(int b = 0; b < m; ++b){
                fin >> matrix[a][b];
            }
        }

        int res = 0;
        for(int c = 0; c < m; ++c){
            std::vector<int> column(n);
            for(int r = 0; r < n; ++r){
                column[r] = matrix[r][c];
            }

            // For each column
            std::sort(column.begin(), column.end());
            int pre = 0;

            for(int i = 0; i < column.size(); ++i){
                res += column[i] * i - pre;
                pre += column[i]; 
            }
        }

        fout << res << "\n";
    }
}