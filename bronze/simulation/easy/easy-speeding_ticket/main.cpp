
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
int main(){
    std::ifstream fin("speeding.in");
    std::ofstream fout("speeding.out");

    int N, M;

    fin >> N >> M;

    std::vector<int> N_dis(N);
    std::vector<int> N_lim(N);
    std::vector<int> M_dis(M);
    std::vector<int> M_lim(M);
    for(int i = 0; i < N; ++i)
        fin >> N_dis[i] >> N_lim[i];

    for(int i = 0; i < M; ++i)
        fin >> M_dis[i] >> M_lim[i];

    int current_N_seg = 0;
    int sum_N = 0;
    int current_M_seg = 0;
    int sum_M = 0;
    int max = INT_MIN;

    for(int mile = 1; mile <= 100; ++mile){
        if(mile - sum_N > N_dis[current_N_seg]){
            sum_N += N_dis[current_N_seg];
            ++current_N_seg;
        }

        if(mile - sum_M > M_dis[current_M_seg]){
            sum_M += M_dis[current_M_seg];
            ++current_M_seg;
        }

        int over_amount = M_lim[current_M_seg] - N_lim[current_N_seg];

        max = std::max(max, over_amount);
    }
    
    max = max > 0 ? max : 0;

    fout << max;
}