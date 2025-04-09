#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl '\n'
#define invec(v, n) for (ll i = 0; i < n; i++) cin >> v[i];

bool f(ll x, ll n, ll k, vll& a) {
    ll cnt = 1;
    priority_queue<ll> pq;
    for (ll i = 0; i < n; i++) {
        if (!pq.empty()) {
            ll top = pq.top();
            if (a[i] == top + 1) {
                pq.push(a[i]);
            }
            if (pq.top() == x) {
                cnt++;
                while (!pq.empty()) pq.pop();
            }
        }
        else if (a[i] == 0) {
            pq.push(a[i]);
        }
    }

    return cnt >= k;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    invec(a, n);

    // cout<<n<<k<<nl;

    ll ans = 0;
    ll lo = 0, hi = 1e9;
    while (lo <= hi) {
        ll mid = lo + ((hi - lo) >> 1);
        if (f(mid, n, k, a)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)  // Loop for each test case
    solve();

    return 0;
}
