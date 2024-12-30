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

using namespace std;

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

// Print all Permutations of a string
void solve1() {
    ll n  = 5;
    auto f = [&](ll idx, ll mask, string s, auto &&F) -> void {
        if(idx == n){
            cout << s << nline;
            return;
        }

        for(ll i=0; i<n; i++){
            if((mask & (1<<i)) == 0){ // if the ith element is not present in the mask
                s += to_string(i+1);
                mask |= (1<<i); // set the ith bit

                F(idx+1, mask, s, F);

                // mask ^= (1<<i); // unset the ith bit
                mask &= ~(1<<i); // unset the ith bit
                s.pop_back();
            }
        }
    };

    f(0, 0, "", f);
}
// Time Complexity: O(n * n!)
//  |-> n! is the number of permutations i.e. the number of calls to the recursive function
//  |-> n is the number of elements in the set (the loop runs n times in each call)


// Without the string, the code respresents 
//    |-> Iterating over all the permutations of a set of numbers
//        of size n


void solve4(){

}


void solve2() {
    ll n  = 5;
    auto f = [&](ll idx, ll mask, auto &&F) -> void {
        if(idx == n){
            return;
        }

        for(ll i=0; i<n; i++){
            if((mask & (1<<i)) == 0){ // if the ith element is not present in the mask
                mask |= (1<<i); // set the ith bit

                F(idx+1, mask, F);

                mask &= ~(1<<i); // unset the ith bit
            }
        }
    };

    f(0, 0, f);
}


// Can we memoize the above code?
// Yes, we can memoize the above code using a 2D dp array
void solve3() {

    // dp[i][mask] = number of ways to place the ith element in the mask, 
    // s.t. mask represents the set of elements present in the subset already
    // and i represents the ith element
    // Note: bit at the ith position in mask will be 0,
    // because then only we are calling the recursive function


    ll n  = 5;

    vector<vector<ll>> dp(n, vector<ll>((1<<n), -1));

    auto f = [&](ll idx, ll mask, auto &&F) -> int {
        if(idx == n){
            return 1;
        }

        if(dp[idx][mask] != -1){
            return dp[idx][mask];
        }

        int ways = 0;

        for(ll i=0; i<n; i++){
            if((mask & (1<<i)) == 0){ // if the ith element is not present in the mask
                mask |= (1<<i); // set the ith bit

                ways += F(idx+1, mask, F);

                mask &= ~(1<<i); // unset the ith bit
            }
        }

        return dp[idx][mask] = ways;
    };

    cout<<f(0, 0, f);
}

// Time Complexity: 
//    |-> f(idx, mask) = O(n * 2^n)
//    |-> and we are calling f() n times (the loop runs n times in each call)
//    |-> So, the time complexity of the above code is O(n^2 * 2^n)

// Time Complexity = number of states * time taken to compute each state
// Here, number of states = n * 2^n
// and time taken to compute each state = O(n) (as we are iterating over n elements in each call)
// So, the time complexity of the above code is O(n^2 * 2^n)




// Hence, we have improved the time complexity of the code 
// from O(n * n!) to O(n^2 * 2^n)
// by using memoization



int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    // solve1();
    // solve2();
    solve3();
    return 0;
}