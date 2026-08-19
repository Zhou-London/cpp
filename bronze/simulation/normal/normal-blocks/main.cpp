

#include <algorithm>
#include <fstream>
#include <string>

int main(){
    // For each word pair
    // For each letter
    // Count its freq in A
    // Count its freq in B
    // Take max (Ac, Bc)
    // Add these max together
    // Output

    std::ifstream fin("blocks.in");
    std::ofstream fout("blocks.out");

    int N;
    fin >> N;

    int freq[26] = {0};

    for(int i = 0; i < N; ++i){
        std::string A, B;
        fin >> A >> B;

        int Ac[26] = {0};
        int Bc[26] = {0};

        for(const auto c : A) Ac[c - 'a']++;
        for(const auto c : B) Bc[c - 'a']++;

        for(int j = 0; j < 26; ++j)
            freq[j] += std::max(Ac[j], Bc[j]);
    }

    for(const auto c : freq)
        fout << c << "\n";

    return 0;
}