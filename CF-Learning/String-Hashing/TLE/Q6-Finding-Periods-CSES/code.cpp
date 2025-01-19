#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define sz(x) ((int)(x).size())
 
typedef long long ll;
 
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
 
struct Hashing
{
    string s;
    int n;
    int primes;
    vector<long long> hashPrimes = {1000000009};
    const long long base = 31;
    vector<vector<long long> > hashValues;
    vector<vector<long long> > powersOfBase;
    vector<vector<long long> > inversePowersOfBase;
    Hashing(string a)
    {
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }
        }
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    long long substringHash(int l, int r) // O(1)
    {
        long long hash;
        long long val1 = hashValues[0][r];
        long long val2 = l > 0 ? hashValues[0][l - 1] : 0LL;
        hash = (((val1 - val2) + hashPrimes[0]) * inversePowersOfBase[0][l]) % hashPrimes[0];
        return hash;
    }
};

// abc

// a*B^2 + b*B^1 + c*B^0

// abcd
// a*B^3 + b*B^2 + c*B^1 + d*B^0
// 
 
// a*B^0 + b*B^1 + c*B^2 + d*B^3
 
void solve() {
    string s; cin>>s;
    ll n = s.size();
 
    Hashing h(s);
    vector<ll> dp(n+1, 0);
 
    for(ll window_len=1; window_len<=n; window_len++){ // O(n) 
        bool flag = true;
        for(ll curridx = 0; curridx < n; curridx+=window_len){
            ll len = min(window_len, n - curridx); // imagine the case where the string len is 7, and window_len is 5, then we need to take 2 characters only
            ll l1 = 0, r1 = len - 1;
            ll l2 = curridx, r2 = curridx + len - 1;
            if(h.substringHash(l1, r1) != h.substringHash(l2, r2)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<window_len<<" ";
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}