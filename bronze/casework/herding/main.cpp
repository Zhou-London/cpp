
#include <algorithm>
#include <fstream>
int main(){

    std::ifstream fin("herding.in");
    std::ofstream fout("herding.out");

    int a, b, c;
    fin >> a >> b >> c;

    // * Evaluate min
    int min = 1 << 10;
    if(b - a == 2 || c - b == 2)
        min = 1;
    else if(a + 2 == c)
        min = 0;
    else
        min = 2;

    // * Evaluate max
    int max = std::max(b - a - 1, c - b - 1);

    fout << min << "\n" << max << "\n";

    return 0;
}