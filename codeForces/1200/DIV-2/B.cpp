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
    vll a(n);
    invec(a, n);
    
    vll prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + a[i];
    }

    ll m; cin >> m;
    while(m--){
        ll q; cin >> q;

        ll l = 0, r = n-1;
        while(l < r){
            ll mid = (l+r)/2;
            if(prefix[mid] >= q){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        cout << r+1 << endl;
    }
}

int main(){
    fastio();

    solve();

    return 0;
}