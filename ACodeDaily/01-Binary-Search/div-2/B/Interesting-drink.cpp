#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>

using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    ll n; cin >> n;
    vll x(n);
    invec(x, n);
    sort(x.begin(), x.end());
    ll q; cin >> q;
    while(q--){
        ll m; cin >> m;
        ll l = 0, r = n;
        while(l < r){
            ll mid = (r-l)/2 + l;
            if(x[mid] <= m){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
}

int32_t main() {
    fastio();
    solve();
    return 0;
}