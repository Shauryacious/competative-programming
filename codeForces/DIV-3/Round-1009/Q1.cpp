#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

// Function to compute squared distance between two points
ll dist2(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.first - b.first) * (a.first - b.first) + 
           (a.second - b.second) * (a.second - b.second);
}

// Function to check if the given four points form a square
bool isSquare(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3, pair<ll, ll> p4) {
    vector<ll> dists = {
        dist2(p1, p2), dist2(p1, p3), dist2(p1, p4),
        dist2(p2, p3), dist2(p2, p4), dist2(p3, p4)
    };

    // Sort the distances
    sort(dists.begin(), dists.end());

    // A square must have 4 equal sides and 2 equal diagonals
    return (dists[0] > 0 && 
            dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3] &&
            dists[4] == dists[5] && 
            2 * dists[0] == dists[4]); // Diagonal must be sqrt(2) times the side
}

void solve() {
    ll l, r, d, u;
    cin >> l >> r >> d >> u;

    // Convert left and down coordinates to negative values
    pair<ll, ll> p1 = {-l, 0}, p2 = {r, 0}, p3 = {0, -d}, p4 = {0, u};

    if (isSquare(p1, p2, p3, p4)) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
