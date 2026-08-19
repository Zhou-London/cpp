#include <bits/stdc++.h>
using namespace std;

struct Graze {
    int x, y, t;

    // ! Custom operator
    bool operator<(const Graze& g) const {
        return t < g.t;
    }
};

bool cant_reach(Graze g1, Graze g2) {
    long long dt = g1.t - g2.t;
    long long dx = g1.x - g2.x;
    long long dy = g1.y - g2.y;
    return dt * dt < dx * dx + dy * dy; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int G, N;
    cin >> G >> N;

    vector<Graze> input(G);
    for (int i = 0; i < G; i++) {
        cin >> input[i].x >> input[i].y >> input[i].t;
    }

    sort(input.begin(), input.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool crime = true;

        int x, y, t;
        cin >> x >> y >> t;
        
        auto p = upper_bound(input.begin(), input.end(), Graze{0, 0, t});
        Graze tmp{x, y ,t};

        if (p != input.end()) {
            if (cant_reach(tmp, *p)) {
                crime = false;
            }
        }
        if (p > input.begin()) {
            if (cant_reach(tmp, *(p - 1))) {
                crime = false;
            }
        }

        if (!crime) {
            ans++;
        }
    }

    cout << ans;
}