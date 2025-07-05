// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you 3000 mumma <3

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
#define py cout<<"YES"<<nl
#define pn cout<<"NO"<<nl
#define pm cout<<"-1"<<nl




// Typedef
typedef int ll;
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

// DEEBUG

// Macros
#define all(x) (x).begin(), (x).end()
#define invec(v, n) for (ll i = 0; i < n; i++) cin >> v[i]
/*---------------------------------------------------------------------------------------------------------------------------*/



void solve() {
    ll n; cin>>n;
    vll a(n); invec(a, n);

    map<ll, ll> dp;
    ll start = -1, len = 0;
    for(ll i=0; i<n; i++){
        ll x = a[i];
        // if x is not present in the map, then it will be 0
        // so it will be the first element of the subsequence
        // hence the Base Case: initialising dp[x] = 1
        dp[x] = max((dp[x]), 1); 

        // if x-1 is present in the map, then we can add x to the subsequence
        // hence dp[x] = dp[x-1] + 1
        dp[x] = max(dp[x], (dp[x-1]+1));

        if(dp[x] > len){
            len = dp[x];
            start = x - len + 1; // the seq will be x-len+1, x-len+2, x-len+3, ...,(x - len + len = x)
        }
    }

    vll ans;
    for(ll i=0; i<n; i++){
        if(a[i] == start){
            ans.pb(i+1);
            start++;
        }
    }

    cout<<len<<nl;
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<nl;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    ll t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}