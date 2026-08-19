

#include <algorithm>
#include <fstream>
#include <vector>
int main(){
    std::ifstream fin("distance.in");
    std::ofstream fout("distance.out");

    int N;
    fin >> N;

    std::vector<int> vecX(N);
    std::vector<int> vecY(N);

    for(int i = 0; i < N; ++i) fin >> vecX[i];
    for(int i = 0; i < N; ++i) fin >> vecY[i];

    int max_dis = 0;

    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            int square = (vecX[i] - vecX[j]) * (vecX[i] - vecX[j])
                        + (vecY[i] - vecY[j]) * (vecY[i] - vecY[j]); 

            max_dis = std::max(max_dis, square);
        }
    }

    fout << max_dis;

    return 0;
}