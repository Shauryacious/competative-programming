#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define vll vector<long long>
#define nline "\n"
// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)


void invec(vll &v, ll n) {
    v.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void solve() {
    ll n, m, k; 
    cin >> n >> m >> k;
    vll a; 
    invec(a, n);
    vll b; 
    invec(b, m);

    map<ll, ll> mb;
    for (auto x : b) {
        mb[x]++;
    }

    ll i = 0, j = 0;
    ll cnt = 0;
    ll ans = 0;
    map<ll, ll> ma;
    while (j < n) {
        if (mb.find(a[j]) != mb.end()) {
            if (ma[a[j]] < mb[a[j]]) {
                cnt++;
            }
            ma[a[j]]++;
        }
        if (j - i + 1 == m) {
            if (cnt >= k) {
                ans++;
            }
            if (mb.find(a[i]) != mb.end()) {
                if (ma[a[i]] <= mb[a[i]]) {
                    cnt--;
                }
                ma[a[i]]--;
                if (ma[a[i]] == 0) {
                    ma.erase(a[i]);
                }
            }
            i++;
        }
        j++;
    }

    cout << ans << nline;
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    ll t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}