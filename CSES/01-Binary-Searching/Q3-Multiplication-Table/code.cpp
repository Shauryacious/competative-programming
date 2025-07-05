#include <iostream>
#include <vector>
#include <algorithm>

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

bool f(ll x, ll mid_idx, ll n){
    ll count = 0;

    //no of ele that are less than or equal to x(ans)
    for(int i=1; i<=n; i++){
        count += min(n, x/i);
    }

    return count >= mid_idx;
}

void solve() {
    ll n; cin >> n;
    ll mid_idx = (n*n)/2 + 1;

    ll l = 0, r = n*n+1;
    while(l<r-1){
        ll m = (r-l)/2 + l;
        if(f(m, mid_idx, n)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout<<r<<endl;
}

int32_t main() {
    fastio();

        solve();

    return 0;
}
