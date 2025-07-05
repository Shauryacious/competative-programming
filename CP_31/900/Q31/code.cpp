// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i];

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Functions
template <typename T>
T sumvec(const vector<T>& vec) { T sum = 0; for (auto val : vec) sum += val; return sum;}

void solve() {
    long long n;
    cin >> n;
    
    ll powOf2 = 0;
    // Check for factors 2 and 3
    while (n % 2 == 0){
        n /= 2;
        powOf2++;
    }
    ll powOf3 = 0;
    while (n % 3 == 0){
        n /= 3;
        powOf3++;
    }

    ll noOf6 = min(powOf2, powOf3);
    
    // If the remaining number is 1, n has only factors 2 and 3
    if (n == 1) {
        if(powOf2 > powOf3) {
            cout <<-1<< endl;
        } else {
            cout << powOf3 + (powOf3 - noOf6) << endl;
        }
    } else {
        cout <<-1<< endl;
    }
}

int32_t main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}