#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>

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

void solve(){
    ll n = 16;
    vll a(n);
    invec(a, n);
    vector<pair<ll, ll>> b;
    for(int i = 0; i < n; i++){
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());

    vector<ll> c = {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4};
    for(int i = 0; i < n; i++){
        b[i].first = c[i];
    }
    sort(b.begin(), b.end(), [](pair<ll, ll> x, pair<ll, ll> y){
        return x.second < y.second;
    });

    for(int i = 0; i < n; i++){
        cout << b[i].first << " ";
    }
}

int32_t main(){
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
