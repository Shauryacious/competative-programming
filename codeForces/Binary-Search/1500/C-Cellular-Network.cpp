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

bool check(ll r, ll n, ll m, vll& a, vll& b){
    ll i = 0, j = 0;
    while(j < m && i < n){
        ll tower = b[j];
        ll city = a[i];
        ll diff = abs(tower - city);
        if(diff <= r){ // the city is in range of the tower => check next city
            i++;
        }
        else{ // the city is NOT in range of the tower => use next Tower
            j++;
        }
    }
    return (i >= n); // all cities are covered
}

void solve(){
    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    invec(a, n);
    invec(b, m);

    ll l = 0, u = 2e9;
    while(u - l >= 1){ 
        ll mid = (u-l)/2 + l;
        if(check(mid, n, m, a, b)){
            u = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout << u << endl; // The minimum range that covers all cities
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();


        solve();

    return 0;
}