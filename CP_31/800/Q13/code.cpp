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
T sumvec(const vector<T>& vec) {
    T sum = 0;
    for (auto val : vec) sum += val;
    return sum;
}

void solve() {
    ll n; cin >> n;
    vll b(n);
    invec(b, n);
    vll a;
    a.push_back(b[0]);

    for(int i=0; i<n-1; i++){
        if(b[i]>b[i+1]){
            a.push_back(b[i+1]);
            a.push_back(b[i+1]);
        }
        else{
            a.push_back(b[i+1]);
        }
    }

    cout << a.size() << endl;
    for(auto x: a){
        cout << x << " ";
    }
    cout<<endl;
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