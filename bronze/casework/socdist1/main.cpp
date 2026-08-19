
#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ifstream fin("socdist1.in");
    std::ofstream fout("socdist1.out");

    int N;
    std::string stalls;

    fin >> N;
    fin >> stalls;

    // Process dist to right
    std::vector<int> to_right(N);
    int next1 = INT_MAX; // next1's index
    for(int i = stalls.size() - 1; i >= 0; --i){
        if(stalls[i] == '1'){
            next1 = i;
            to_right[i] = 0;
        } else {
            to_right[i] = next1 == INT_MAX ? INT_MAX : next1 - i;
        }
    }

    // Process min dist between two cows
    int minDist = INT_MAX;
    int prev = -1;
    for(int i = 0; i < stalls.size(); ++i){
        if(stalls[i] == '1'){
            if(prev >= 0) minDist = std::min(minDist, i - prev);
            prev = i;
        }
    }

    auto checkD = [&](const int D){
        // * Check existing min distance
        if(minDist < D)
            return false;

        // * Place new cows
        int to_place = 2;
        int prev = -1;
        for(int i = 0; i < stalls.size(); ++i){
            if(stalls[i] == '1'){
                prev = i;
                continue;
            } else {
                int to_left = prev >= 0 ? i - prev : INT_MAX;

                if(to_left >= D && to_right[i] >= D && to_place > 0){
                    prev = i;
                    --to_place;
                }
            }
        }

        return to_place == 0;
    };

    // Binary search the answer
    int D_min = 1;
    int D_max = N - 1;

    while(D_min < D_max){
        int D = (D_max + D_min + 1) / 2;

        if(checkD(D)){
            D_min = D;
        } else {
            D_max = D - 1;
        }
    }

    fout << D_min << "\n";

    return 0;
}