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
    ll n; cin>>n;
    vll a(n);
    invec(a, n);

    vll pre(n);
    vll post(n);

    pre[0] = 0;
    post[n-1] = 0;

    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + a[i-1];
    }
    for(int i=0; i<n; i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for(int i=n-2; i>=0; i--){
        post[i] = post[i+1] + a[i+1];
    }
    for(int i=0; i<n; i++){
        cout<<post[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<n; i++){
        if(pre[i] == post[i-1]){
            cout<<i-1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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