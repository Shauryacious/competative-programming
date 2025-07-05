#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

// Typedef
typedef long long ll;
typedef vector<ll> vll;

#define nline "\n"

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<string> s(n);
    priority_queue<ll, vll, greater<ll>> r, y, g, b;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        char c1 = s[i][0];
        if (c1 == 'R') r.push(i);
        if (c1 == 'G') g.push(i);
        if (c1 == 'Y') y.push(i);
        if (c1 == 'B') b.push(i);
    }

    while (q--) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;

        char cx1 = s[x][0];
        char cx2 = s[x][1];
        char cy1 = s[y][0];
        char cy2 = s[y][1];

        if (cx1 == cy1 || cx1 == cy2 || cx2 == cy1 || cx2 == cy2) {
            cout << abs(x - y) << nline;
        } else { // no common color
            ll ans = 0;

            // This lambda function is fine, it takes priority_queue references
            auto calculateDistance = [](priority_queue<ll, vll, greater<ll>>& pq1, priority_queue<ll, vll, greater<ll>>& pq2) -> ll {
                ll minn = LLONG_MAX;
                if (!pq1.empty()) minn = min(minn, pq1.top());
                if (!pq2.empty()) minn = min(minn, pq2.top());
                return minn;
            };

            if (cx1 == 'R' && cx2 == 'G') {
                ll minn = calculateDistance(r, g);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'R' && cx2 == 'Y') {
                ll minn = calculateDistance(r, y);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'R' && cx2 == 'B') {
                ll minn = calculateDistance(r, b);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'G' && cx2 == 'R') {
                ll minn = calculateDistance(g, r);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'G' && cx2 == 'Y') {
                ll minn = calculateDistance(g, y);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'G' && cx2 == 'B') {
                ll minn = calculateDistance(g, b);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'Y' && cx2 == 'R') {
                ll minn = calculateDistance(y, r);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'Y' && cx2 == 'G') {
                ll minn = calculateDistance(y, g);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'Y' && cx2 == 'B') {
                ll minn = calculateDistance(y, b);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'B' && cx2 == 'R') {
                ll minn = calculateDistance(b, r);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'B' && cx2 == 'G') {
                ll minn = calculateDistance(b, g);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            } else if (cx1 == 'B' && cx2 == 'Y') {
                ll minn = calculateDistance(b, y);
                if (minn != x && minn != y) {
                    ans += abs(x - minn);
                    ans += abs(y - minn);
                }
            }

            if (ans == 0) {
                cout << -1 << nline;
            } else {
                cout << ans << nline;
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}