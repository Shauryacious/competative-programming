#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i];

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Functions
template <typename T>
T sumvec(const vector<T>& vec) { T sum = 0; for (auto val : vec) sum += val; return sum;}

void solve() {
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    if(y2 < y1){
        cout<<-1<<endl;
        return;
    }
    ll c = y1 - x1;
    if(y2 < x2 + c){
        cout<<-1<<endl;
        return;
    }
    if(x1 == x2 && y1 == y2){
        cout<<0<<endl;
        return;
    }
    if(y1 == y2){
        cout<<abs(x2 - x1)<<endl;
        return;
    }
    ll yinc = abs(y2 - y1);
    if(x2 > x1){
        ll xinc = yinc - abs(x2 - x1);
        cout<<yinc + xinc<<endl;
    }
    else if(x1 > x2){
        ll xinc = yinc + abs(x1 - x2);
        cout<<yinc + xinc<<endl;
    }
    else{
        cout<<2*yinc<<endl;
    
    }
}

int32_t main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
