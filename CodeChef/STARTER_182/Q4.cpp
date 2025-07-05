// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you ∞ mumma <3

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
#define invec(v, n) for (ll i = 0; i < n; i++) cin >> v[i]
/*---------------------------------------------------------------------------------------------------------------------------*/




// void solve() {
//     ll n, k; cin >> n >> k;
//     string s; cin >> s;
//     // reverse(s.begin(), s.begin() + n - 2);
//     debug(s);

//     bool f = false;
//     for(ll i = 0; i < n; i++){
//         char ch = s[i];
//         ll cnt = 0;
//         bool used = false;
//         while(i < n && s[i] == ch){
//             cnt++;
//             if(cnt == k){
//                 debug(i);
//                 ll j = i;
//                 while(j < n && s[j] == ch){
//                     j++;
//                 }
//                 if(j < n){
//                     char ch2 = s[j];
//                     debug(j);
//                     // reverse(s.begin() + i, s.begin() + j + 1); // FIXED
//                     if(j+1 < n && s[j+1] != ch2){
//                         char ch3 = s[j+1];
//                         ll jj = j + 1;
//                         ll cnt3 = 0;
//                         while(jj < n && s[jj] == ch3){
//                             jj++;
//                             cnt3++;
//                         }
//                         if(cnt3 >= (k-1)){ // We have to discard this G choice, and look for a better G
                            
//                         }
//                     }
//                     else{
//                         reverse(s.begin() + i, s.begin() + j + 1);
//                     }
//                     used = true;
//                     debug(s);
//                 }
//                 else if(j == n){
//                     pn;
//                     return;
//                 }
//             }
//             i++;
//             if(used){
//                 f = true;
//                 break;
//             }
//         }
//         i--;
//         if(f) break;
//     }

//     for(ll i = 0; i < n; i++){
//         char ch = s[i];
//         ll cnt = 0;
//         while(i < n && s[i] == ch){
//             cnt++;
//             if(cnt >= k){
//                 pn;
//                 return;
//             }
//             i++;
//         }
//     }

//     py;
// }





void solve() {
    ll n, k; 
    cin >> n >> k;
    string s; 
    cin >> s;
    debug(s);

    bool performed = false;
    // Try to find a candidate block to reverse
    for (ll i = 0; i < n; i++) {
        char cur = s[i];
        ll cnt = 0;
        bool op_done = false;
        // Count consecutive same characters
        while(i < n && s[i] == cur) {
            cnt++;
            // When block length reaches k, check candidate for reversal
            if(cnt == k) {
                debug(i);
                ll j = i;
                // Move j until the group of cur ends
                while(j < n && s[j] == cur)
                    j++;
                    debug(j);
                // If there is a next group...
                if(j < n) {
                    char candidate = s[j];
                    debug(j);
                    // If there is an element after the candidate group and it is different,
                    // we may have a problematic reversal.
                    if(j + 1 < n && s[j + 1] != candidate) {
                        char nextChar = s[j + 1];
                        ll jj = j + 1;
                        ll cntNext = 0;
                        // Count the consecutive nextChar after candidate group
                        while(jj < n && s[jj] == nextChar) {
                            cntNext++;
                            jj++;
                        }
                        // If the candidate group would “steal” one from a group that is exactly k–1 long,
                        // then skip this candidate.
                        debug(cntNext);
                        if(cntNext == (k - 1)) {
                            // j++;
                            // Skip this candidate reversal and let the loop continue
                            ;
                        }
                        // If the next group is already too long, the answer is "NO"
                        else if(cntNext >= k) {
                            pn;
                            return;
                        }
                        else {
                            // Otherwise safe to reverse
                            reverse(s.begin() + i, s.begin() + j + 1);
                            op_done = true;
                        }
                    }
                    else {
                        // Either there is no element after j or the next element is the same as candidate:
                        // safe to reverse.
                        reverse(s.begin() + i, s.begin() + j + 1);
                        op_done = true;
                        debug(op_done);
                    }
                    if(op_done) {
                        debug(s);
                        performed = true;
                        break;
                    }
                }
                // If there is no candidate (j==n) then we cannot do any reversal.
                else if(j == n) {
                    pn;
                    return;
                }
            }
            i++;
        }
        i--;  // readjust index since inner loop advanced it
        if(performed)
            break;
    }

    // Final check: if any segment of length >= k exists, output "NO"
    for(ll i = 0; i < n; i++){
        char cur = s[i];
        ll cnt = 0;
        while(i < n && s[i] == cur) {
            cnt++;
            if(cnt >= k) {
                pn;
                return;
            }
            i++;
        }
    }
    py;
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