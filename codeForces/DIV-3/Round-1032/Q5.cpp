// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<random>
#include<string>
#include<functional>
#include<iomanip>
#include<limits>
#include<array>
#include<utility>
#include<cstring>

using namespace std;

using namespace std;
using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nl '\n'
const ll MAXN = 20;
const ll INF = 1e9;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)



string L, R;
ll N;
ll dp[MAXN][2][2]; 

ll dfs(ll pos, ll tL, ll tR) {
    if (pos == N) return 0;
    ll &ans = dp[pos][tL][tR];
    if (ans != -1) return ans;
    ans = INF;
    ll lo = tL ? (L[pos] - '0') : 0;
    ll hi = tR ? (R[pos] - '0') : 9;
    for (ll d = lo; d <= hi; d++) {
        ll ntL = tL && (d == lo);
        ll ntR = tR && (d == hi);
        ll cost = (d == (L[pos]-'0')) + (d == (R[pos]-'0'));
        ans = min(ans, cost + dfs(pos+1, ntL, ntR));
    }
    return ans;
}

void solve() {
    cin >> L >> R;
    N = L.size();
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,1,1) << nl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    // setIn("input.txt");
    // setOut("output.txt");
    ll t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}