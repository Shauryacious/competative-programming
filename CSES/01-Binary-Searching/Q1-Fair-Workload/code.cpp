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

bool f(ll x, const vll& arr, ll k){
    ll sum = 0;
    ll Usedworker = 1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > x){
            return false;
        }
        if(sum + arr[i] <= x){
            sum += arr[i];
        }
        else{
            Usedworker++;
            sum = arr[i];
        }
    }
    return Usedworker <= k;
}

// https://cses.fi/problemset/task/1085
void solve() {
    ll n, k; cin >> n >> k;
    vll arr(n);
    invec(arr, n);

    ll l = 0;
    ll u = 1e18;
    ll ans = 0;
    while(l <= u){
        ll mid = (u - l) / 2 + l;
        if(f(mid, arr, k)){
            ans = mid+1;
            u = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << l << endl;
}

int32_t main() {
    fastio();
    solve();
    return 0;
}