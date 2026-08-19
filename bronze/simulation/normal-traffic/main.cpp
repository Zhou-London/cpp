
#include <algorithm>
#include <climits>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
int main(){
    std::ifstream fin("traffic.in");
    std::ofstream fout("traffic.out");

    int N;
    fin >> N;
    
    std::vector<std::string> ramp(N);
    std::vector<int> low(N);
    std::vector<int> high(N);

    int lo = 0;
    int hi = 1000;

    for(int i = 0; i < N; ++i)
        fin >> ramp[i] >> low[i] >> high[i];


    for(int i = N - 1; i >= 0; --i){
        if(ramp[i] == "on"){
            lo -= high[i];
            hi -= low[i];

            lo = std::max(lo, 0);
        } else if (ramp[i] == "off") {
            lo += low[i];
            hi += high[i];
        } else {
            lo = std::max(lo, low[i]);
            hi = std::min(hi, high[i]);
        }
    }

    fout << lo << " " << hi << "\n";

    lo = 0;
    hi = 1000;

    for(int i = 0; i < N; ++i){
        if(ramp[i] == "on"){
            lo += low[i];
            hi += high[i];
        } else if (ramp[i] == "off") {
            lo -= high[i];
            hi -= low[i];

            lo = std::max(lo, 0);
        } else {
            lo = std::max(lo, low[i]);
            hi = std::min(hi, high[i]);
        }
    }

    fout << lo << " " << hi << "\n";
}