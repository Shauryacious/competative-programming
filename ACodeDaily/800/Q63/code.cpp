#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;  // Number of levels

    set<int> levels;  // To store unique levels they can pass

    int p, q, level;
    
    cin >> p;  // Number of levels Little X can pass
    for (int i = 0; i < p; i++) {
        cin >> level;
        levels.insert(level);
    }

    cin >> q;  // Number of levels Little Y can pass
    for (int i = 0; i < q; i++) {
        cin >> level;
        levels.insert(level);
    }

    // If all levels from 1 to n exist in the set, they can complete the game
    if ((int)levels.size() == n) {
        cout << "I become the guy.\n";
    } else {
        cout << "Oh, my keyboard!\n";
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
