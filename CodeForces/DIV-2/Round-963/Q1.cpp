#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    ll n; cin >> n;

    string s; cin >> s;
    ll ca = 0, cb = 0, cc = 0, cd = 0, cq = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'A') ca++;
        if(s[i] == 'B') cb++;
        if(s[i] == 'C') cc++;
        if(s[i] == 'D') cd++;
        if(s[i] == '?') cq++;
    }

    // cout << ca << " " << cb << " " << cc << " " << cd << " " << cq << endl;
    ll t = 0;
    if(ca >= n) t += n;
    else t += ca;
    if(cb >= n) t += n;
    else t += cb;
    if(cc >= n) t += n;
    else t += cc;
    if(cd >= n) t += n;
    else t += cd;
    cout << t << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}