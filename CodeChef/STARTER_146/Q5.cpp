#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

void solve(){
    ll n; cin >> n;
    vll ans(n);
    ll i = 0;
    ll count = 1;

    while(i < count){
        ans[i] = count;
        count++;
        i+=2;
    }

    i = 1;

    while(i < n){
        ans[i] = count;
        count++;
        i+=2;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
}

int32_t main(){
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}