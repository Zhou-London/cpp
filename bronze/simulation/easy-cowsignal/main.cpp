
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main(){
    std::ifstream fin("cowsignal.in");
    std::ofstream fout("cowsignal.out");

    int M, N, K;
    fin >> M >> N >> K;

    std::vector<std::string> output;
    output.reserve(M * K);

    for(int i = 0; i < M; ++i){
        std::string origin;
        fin >> origin;

        std::string scaled;
        for(int i = 0; i < N; ++i)
            for(int s = 0; s < K; ++s)
                scaled += origin[i];

        for(int s = 0; s < K; ++s)
            output.push_back(scaled);
    }

    for(const auto& str: output)
        fout << str << "\n";

    return 0;
}