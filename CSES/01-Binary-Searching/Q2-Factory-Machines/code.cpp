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
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Functions
template <typename T>
T sumvec(const vector<T>& vec) { T sum = 0; for (auto val : vec) sum += val; return sum;}

bool f(ll x, ll t, vector<ll>& machines) {
    // x is the amount of time(value of mid) for which we need to check, that wheater it is enough or not 
    ll currProductProduced = 0;
    for(auto machineTime : machines) {
        if (currProductProduced >= t) return true;  // Early exit if we already have enough products
        currProductProduced += (x / machineTime); 
        if (currProductProduced < 0) return true;  // Detect overflow, treat as enough products
    }
    return currProductProduced >= t;
}

// https://cses.fi/problemset/task/1620
void solve() {
    ll n, t; 
    cin >> n >> t;
    // n = number of machines
    // t = number of products we want
    vll machines(n);
    invec(machines, n);

    ll l = 0, u = 1e18;
    ll ans = 1e18;
    while(l <= u) {
        ll mid = (u - l) / 2 + l;
        if(f(mid, t, machines)) {
            ans = mid;
            u = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fastio();
    solve();
    return 0;
}