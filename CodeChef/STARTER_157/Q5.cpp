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

#include <bits/stdc++.h>
using namespace std;

// Count subarrays with all equal values
long long countEqualValSubarrays(vector<int>& arr, int target) {
    long long totalSubarrays = 0;
    int currentRun = 0;
    
    for (int element : arr) {
        if (element == target) {
            currentRun++;
        } else {
            if (currentRun >= 2) {
                totalSubarrays += (1LL * currentRun * (currentRun - 1)) / 2;
            }
            currentRun = 0;
        }
    }
    if (currentRun >= 2) {
        totalSubarrays += (1LL * currentRun * (currentRun - 1)) / 2;
    }
    return totalSubarrays;
}

void solveTestCase() {
    int arraySize;
    cin >> arraySize;
    
    vector<int> inputArray(arraySize);
    for (int i = 0; i < arraySize; i++) {
        cin >> inputArray[i];
    }
    
    long long totalCount = arraySize;  // Single element subarrays
    totalCount += countEqualValSubarrays(inputArray, 1);
    totalCount += countEqualValSubarrays(inputArray, 3);
    
    // Create auxiliary array based on input values: 1->1, 2->0, 3->-1
    vector<int> transformedArray(arraySize);
    int countOfTwos = 0;
    for (int i = 0; i < arraySize; i++) {
        if (inputArray[i] == 1) transformedArray[i] = 1;
        else if (inputArray[i] == 2) {
            transformedArray[i] = 0;
            countOfTwos++;
        }
        else transformedArray[i] = -1;
    }
    
    // Calculate sumZero using frequency array
    const int OFFSET = arraySize;
    vector<long long> freqArray(2 * arraySize + 1, 0);
    long long sumZero = 0;
    int prefixSum = 0;
    freqArray[prefixSum + OFFSET]++;
    
    for (int i = 0; i < arraySize; i++) {
        prefixSum += transformedArray[i];
        if (0 <= prefixSum + OFFSET && prefixSum + OFFSET < 2 * arraySize + 1) {
            sumZero += freqArray[prefixSum + OFFSET];
            freqArray[prefixSum + OFFSET]++;
        }
    }
    
    // Calculate sumZeroY
    long long sumZeroY = 0;
    int index = 0;
    while (index < arraySize) {
        if (inputArray[index] == 2) {
            index++;
            continue;
        }
        
        int segmentStart = index;
        while (index < arraySize && inputArray[index] != 2) index++;
        int segmentEnd = index;
        int segmentLength = segmentEnd - segmentStart;
        
        if (segmentLength == 0) continue;
        
        vector<int> segmentArray;
        segmentArray.reserve(segmentLength);
        for (int j = 0; j < segmentLength; j++) {
            segmentArray.push_back(inputArray[segmentStart + j] == 1 ? 1 : -1);
        }
        
        const int OFFSET_SEG = segmentLength;
        vector<long long> freqSegment(2 * segmentLength + 1, 0);
        int prefixSegment = 0;
        freqSegment[prefixSegment + OFFSET_SEG]++;
        
        for (int j = 0; j < segmentLength; j++) {
            prefixSegment += segmentArray[j];
            if (0 <= prefixSegment + OFFSET_SEG && prefixSegment + OFFSET_SEG < 2 * segmentLength + 1) {
                sumZeroY += freqSegment[prefixSegment + OFFSET_SEG];
                freqSegment[prefixSegment + OFFSET_SEG]++;
            }
        }
    }
    
    long long additionalSubarrays = sumZero - sumZeroY - countOfTwos;
    totalCount += additionalSubarrays;
    
    cout << totalCount << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        solveTestCase();
    }
    
    return 0;
}
