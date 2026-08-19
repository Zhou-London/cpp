
#include <algorithm>
#include <fstream>
#include <iostream>
struct Rect{
    int x1, y1, x2, y2;

    void read(std::ifstream& fin){
        fin >> x1 >> y1 >> x2 >> y2;
    }
};

int main(){
    std::ifstream fin("square.in");
    std::ofstream fout("square.out");

    Rect a, b;
    a.read(fin);
    b.read(fin);

    int x = std::max(a.x2, b.x2) - std::min(a.x1, b.x1);
    int y = std::max(a.y2, b.y2) - std::min(a.y1, b.y1);

    int len = std::max(x, y);

    fout << len * len << "\n";

    return 0;
}