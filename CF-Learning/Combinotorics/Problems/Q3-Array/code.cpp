// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Codechef: https://www.codechef.com/users/shauryacious27

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>

using namespace std;

#define ll long long
#define vll vector<ll>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll N = 1e6 + 10;
ll M = 1e9 + 7;
vll fact(N+1);
vll ifact(N+1);

ll mod_mul(ll a, ll b, ll M){
    a = a % M;
    b = b % M;
    return (((a*b) % M) + M) % M;
}

ll mod_sub(ll a, ll b, ll M){
    a = a % M;
    b = b % M;
    return (((a-b) % M) + M) % M;
}

ll expo(ll a, ll n, ll M){
    ll ans = 1;
    while(n > 0){
        if((n & 1) == 1){
            ans = mod_mul(ans, a, M);
        }

        n >>= 1;
        a = mod_mul(a, a, M);
    }
    return ans;
}

void precompute(){
    fact[0] = 1;
    for(ll i=1; i<=N; i++){
        fact[i] = mod_mul(i, fact[i-1], M);
    }

    ifact[N] = expo(fact[N], M-2, M); // Fermat's Little theorem for modular inverse
    for(int i=N-1; i>=0; i--){
        ifact[i] = mod_mul(i+1, ifact[i+1], M);
    }
}

ll nCr(ll n, ll r, ll M){
    if(r > n) return 0;
    ll ans = 1;
    ans = mod_mul(ans, fact[n], M);
    ans = mod_mul(ans, ifact[r], M);
    ans = mod_mul(ans, ifact[n-r], M);
    return ans;
}

void solve(){
    ll n; cin>>n;
    ll ans = 1;
    ans = nCr((2*n-1), n, M);
    ans = mod_mul(ans, 2, M);
    ans = mod_sub(ans, n, M);
    cout << ans << "\n";
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    precompute(); // You forgot to call this in the original code
    ll t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}