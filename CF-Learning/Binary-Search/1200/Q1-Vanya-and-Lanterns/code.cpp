#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()

bool f(lld d, vll &a, lld l) {
    ll n = a.size();
    if (a[0] > d || (l - a[n - 1]) > 2*d) return false; // Ensure start and end are covered
    
    for (ll i = 1; i < n; i++) {
        if ((a[i] - a[i - 1]) > 2 * d) return false; // Check max gap between two lanterns
    }
    
    return true;
}

void solve() {
    ll n, l;
    cin >> n >> l;
    vll a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    lld lo = 0, hi = l, ans = l;
    
    while (hi - lo > 1e-9) {
        lld mid = (lo + hi) / 2.0;
        if (f(mid, a, l)) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    cout << fixed << setprecision(9) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
