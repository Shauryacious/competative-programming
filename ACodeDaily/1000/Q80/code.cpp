// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Codechef: https://www.codechef.com/users/shauryacious27

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Define Constants
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())




// Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pll> vpll;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key, lower_bound, upper_bound
// typedef tree<pair<ll, ll>, null_type, greater<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key for ascending


/*---------------------------------------------------------------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif


vll v;
vll primes;

void sieve(){
    ll N = 100001;
    v.resize(N, 1);
    v[0] = v[1] = 0;
    for(ll i=2; i*i < N; i++){
        if(v[i]){
            for(ll j=i*i; j<N; j+=i){
                v[j] = 0;
            }
        }
    }

    for(ll i=2; i<=N; i++){
        if(v[i]){
            primes.pb(i);
        }
    }
}


void solve() {
    ll d; cin>>d;
    ll ans = 1;
    ll curr = 1;
    ll idx = -1;
    for(ll i=0; i<sz(primes); i++){
        if(primes[i] - curr >= d){
            idx = i;
            curr = primes[i];
            ans *= primes[i];
            break;
        }
    }

    for(ll i=idx+1; i<sz(primes); i++){
        if(primes[i] - curr >= d){
            ans *= primes[i];
            break;
        }
    }

    cout<<ans<<nl;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    ll t = 1; 
    cin >> t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}