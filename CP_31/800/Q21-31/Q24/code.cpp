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
    ll n; cin >> n;
    vll a(n);
    invec(a, n);
    int xor_all = 0;
    for(int i=0; i<n; i++){
        xor_all ^= a[i];
    }
    //if n is even then (a1 ^ x) ^ (a2 ^ x) ^ (a3 ^ x) ^ ... ^ (an ^ x) = a1 ^ a2 ^ a3 ^ ... ^ an
    // so no matter what value of x we choose, the answer would be xor of all the elements
    // so if xor of all the elements is 0 then the answer is any value in the array else -1
    if(n%2 == 0){ 
        if(xor_all == 0){
            cout << a[n-1] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    //else if n is odd then (a1 ^ x) ^ (a2 ^ x) ^ (a3 ^ x) ^ ... ^ (an ^ x) = a1 ^ a2 ^ a3 ^ ... ^ an ^ x
    // so we can just xor all the elements and say it as x, then (a1 ^ a2 ^ a3 ^ ... ^ an) ^ x = x ^ x = 0
    // so the answer would be xor of all the elements
    // xor of all the elements would be that value of x, with which if we xor all the elements we get 0
    else{
        cout << xor_all << endl;
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