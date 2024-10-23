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
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll N = 1e6 + 10;  
ll M = 1e9 + 7;
vll fact(N+1);
vll ifact(N+1);

ll mod_mul(ll a, ll b, ll M){
    a = a % M;
    b = b % M;
    return (((a * b) % M) + M) % M;
}

ll expo(ll a, ll n, ll M){
    ll ans = 1;
    while(n > 0){
        if((n & 1) == 1){  // i.e., Last bit is set
            ans = mod_mul(ans, a, M);
        }
        a = mod_mul(a, a, M);
        n >>= 1;
    }
    return ans;
}

void precompute(){
    fact[0] = 1;
    for(int i=1; i<=N; i++){
        fact[i] = mod_mul(i, fact[i-1], M);
    }

    ifact[N] = expo(fact[N], M-2, M);  // Modular inverse of fact[N-1]
    for(int i=N-1; i>=0; i--){
        ifact[i] = mod_mul(i+1, ifact[i+1], M);
    }
}

void solve(){
    ll n; cin >> n;
    ll ans = 0; 
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            ans = (ans + mod_mul(fact[n], ifact[i], M)) % M;  // Add if i is even
        } else {
            ans = (ans - mod_mul(fact[n], ifact[i], M) + M) % M;  // Subtract if i is odd
        }
    }
    cout << ans << "\n";
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    precompute();
    solve();

    return 0;
}

// https://cses.fi/alon/task/1715