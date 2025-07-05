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
    vll a(n);
    invec(a, n);

    int maxcount = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            int count = 0;
            while(i < n && a[i] == 0) {
                i++;
                count++;
            }
            maxcount = max(maxcount, count);
        }
    }
    cout<<maxcount<<endl;
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
