#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define invec(v, n) for (ll i = 0; i < n; i++) cin >> v[i]
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl "\n"
#define debug(x) cerr << #x << " = " << x << nl

ll n, m, x, y;
vll a, b;

bool f(ll k) {
    if (k == 0) return true;
    if (k > n || k > m) return false;
    ll cnt = 0;
    for (ll i = 0; i < k; i++) {
        ll req = a[n - k + i];
        ll str = b[m - k + i];
        if (str >= req) continue;
        if (str + y >= req) {
            cnt++;
            if (cnt > x) return false;
        } else return false;
    }
    return true;
}

void solve() {
    cin >> n >> m >> x >> y;
    a.resize(n), b.resize(m);
    invec(a, n);
    invec(b, m);
    sort(all(a));
    sort(all(b));

    ll l = 0, r = min(n, m), ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (f(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
