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

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Define Constants
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

// Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vll;


/*---------------------------------------------------------------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

// DEEBUG

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------*/


// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define sumvec(v) accumulate(v.begin(), v.end(), 0)
#define sortvec(v) sort(v.begin(), v.end())
#define revsortvec(v) sort(v.rbegin(), v.rend())
#define maxvec(v) *max_element(v.begin(), v.end())
#define minvec(v) *min_element(v.begin(), v.end())
/*---------------------------------------------------------------------------------------------------------------------------*/

bool f(ll mid, vll a, ll c){
    ll cows = 1;
    ll last = a[0];
    for(int i = 1; i < a.size(); i++){
        ll diff = a[i] - last;
        if(diff >= mid){
            cows++;
            last = a[i];
        }
    }
    return cows >= c;
}

void solve(){
    ll n, c; cin >> n >> c;
    vll a(n);
    invec(a, n);
    sortvec(a);

    ll l = 0, r = maxvec(a);
    while(l + 1 < r){
        ll mid = (r-l)/2 + l;
        if(f(mid, a, c)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}