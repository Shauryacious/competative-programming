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
#include <climits>

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
#define nline "\n"
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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key, lower_bound, upper_bound
// typedef tree<pair<ll, ll>, null_type, greater<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key for ascending


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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //generates random numbers
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll max_ele(vector<ll> v) {return *max_element(v.begin(), v.end());}
ll min_ele(vector<ll> v) {return *min_element(v.begin(), v.end());}
/*---------------------------------------------------------------------------------------------------------------------------*/
vector<ll> sieve(ll n) {vector<ll> isPrime(n + 1, 1);for (ll i = 2; i * i <= n; i++) { if (isPrime[i] == 1) {for (ll j = i * i; j <= n; j += i) { isPrime[j] = 0;}}}vector<ll> primes;for (ll i = 2; i <= n; i++) {if (isPrime[i]) {primes.push_back(i);}}return primes;}
/*---------------------------------------------------------------------------------------------------------------------------*/


// Macros
#define all(x) (x).begin(), (x).end()
#define rep(i, j) for (ll i = 0; i < j; i++)
#define invec(v, n) for (ll i = 0; i < n; i++) cin >> v[i]
#define sortvec(v) sort(v.begin(), v.end())
#define revsortvec(v) sort(v.rbegin(), v.rend())
#define maxvec(v) *max_element(v.begin(), v.end())
#define minvec(v) *min_element(v.begin(), v.end())
/*---------------------------------------------------------------------------------------------------------------------------*/

void solve() {
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    ll L = n + m - 1;
    vector<pair<ll, ll>> path;
    ll r = 0, c = 0;
    path.pb({r, c});
    for (auto ch : s) {
        if (ch == 'D') r++; else c++;
        path.pb({r, c});
    }
    vector<vector<ll>> grid(n, vector<ll>(m));
    vector<vector<bool>> onPath(n, vector<bool>(m, false));
    for (auto &p : path) onPath[p.ff][p.ss] = true;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vll fixedRow(n, 0), fixedCol(m, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (!onPath[i][j]) {
                fixedRow[i] += grid[i][j];
                fixedCol[j] += grid[i][j];
            }
        }
    }
    ll V = n + m; vll B(V, 0);
    for (ll i = 0; i < n; i++)
        B[i] = -fixedRow[i];
    for (ll j = 0; j < m; j++)
        B[n + j] = -fixedCol[j];
    ll E = L;
    vector<vector<pair<ll, ll>>> adj(V);
    for (ll i = 0; i < L; i++) {
        auto pr = path[i];
        ll u = pr.ff, v = n + pr.ss;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    vll deg(V, 0);
    for (ll i = 0; i < V; i++) {
        deg[i] = adj[i].size();
    }
    vector<bool> usedEdge(E, false);
    vll edgeVal(E, 0);
    queue<ll> qu;
    vector<bool> inQueue(V, false), removed(V, false);
    for (ll i = 0; i < V; i++) {
        if (deg[i] == 1) {
            qu.push(i);
            inQueue[i] = true;
        }
    }
    while (!qu.empty()) {
        ll u = qu.front();
        qu.pop();
        if (removed[u] || deg[u] == 0)
            continue;
        ll nei = -1, eid = -1;
        for (auto &p : adj[u]) {
            if (!usedEdge[p.ss]) {
                nei = p.ff;
                eid = p.ss;
                break;
            }
        }
        if (eid == -1)
            continue;
        edgeVal[eid] = B[u];
        removed[u] = true;
        usedEdge[eid] = true;
        B[nei] -= edgeVal[eid];
        deg[u]--;
        deg[nei]--;
        if (deg[nei] == 1 && !removed[nei] && !inQueue[nei]) {
            qu.push(nei);
            inQueue[nei] = true;
        }
    }
    for (ll i = 0; i < L; i++) {
        auto pr = path[i];
        grid[pr.ff][pr.ss] = edgeVal[i];
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << grid[i][j] << (j + 1 == m ? "\n" : " ");
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    ll t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}