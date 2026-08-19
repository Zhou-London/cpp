
#include <cstdlib>
#include <fstream>
int main(){
    std::ifstream fin("lostcow.in");
    std::ofstream fout("lostcow.out");

    int x, y;
    fin >> x >> y;

    int offset = 1;
    int current = x;
    int total = 0;

    while(true){
        int next = x + offset;

        bool found = false;
        if(current > next)
            found = (next <= y && y <= current);
        else
            found = (current <= y && y <= next);

        if(found){
            total += abs(y - current);
            break;
        }
        else
            total += abs(next - current);

        offset *= -2;
        current = next;
    }
    
    fout << total;

    return 0;
}