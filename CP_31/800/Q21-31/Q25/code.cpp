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
    ll n; cin>>n;
    string s; cin>>s;
    ll i=0, j=n-1;
    while(i<j){
        if(s[i] == s[j]){
            cout<<j-i+1<<endl;
            return;
        }
        i++;
        j--;
    }
    if(n%2 == 0){  
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
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
