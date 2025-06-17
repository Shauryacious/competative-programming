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

using namespace std;

#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define M 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18

ll mod_mul(ll a, ll b, ll MOD){
    a %= MOD;
    b %= MOD;
    ll res = (((a * b) % MOD) + MOD) % MOD;
    return res;
}

ll expo(ll a, ll p, ll MOD){
    if(p == 0) return 1LL;
    ll res = 1;
    while(p > 0){
        if(p & 1) res = mod_mul(res, a, MOD);
        a = mod_mul(a, a, MOD);
        p >>= 1;
    }
    return res;
}

ll N = 1e5 + 10;

vll fact(N+1);
vll ifact(N+1);

void pre(){
    fact[0] = fact[1] = 1;
    for(ll i = 2; i <= N; i++){
        fact[i] = mod_mul(fact[i-1], i, M);
    }

    ifact[N] = expo(fact[N], M-2, M);
    for(ll i = N-1; i >= 1; i--){
        ifact[i] = mod_mul(ifact[i+1], i+1, M);
    }
    ifact[0] = 1;
}

ll nCr(ll n, ll r, ll MOD){
    if(r < 0 || r > n) return 0;
    ll res = fact[n];
    res = mod_mul(res, ifact[r], MOD);
    res = mod_mul(res, ifact[n-r], MOD);
    return res;
}

class Solution {
public:
    int countGoodArrays(int NN, int MM, int KK) {
        ll n = (ll)NN, m = (ll)MM, k = (ll)KK;
        static bool initialized = false;
        if(!initialized) {
            pre();
            initialized = true;
        }

        // number of segments = n - k
        ll b = n - k;

        // ways: first element m choices and each unequal adjacent (segments-1) has (m-1)
        ll ans1 = mod_mul(m, expo(m-1, b-1, M), M);

        // choose positions for unequal adjacents out of n-1
        ll ans2 = nCr(n-1, b-1, M);

        ll res = mod_mul(ans1, ans2, M);
        return (int)res;
    }
};
