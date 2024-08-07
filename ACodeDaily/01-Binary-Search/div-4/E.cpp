#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

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

ll f(ll w, ll n, vll &v){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (v[i] + w) * (v[i] + w); //Probably, the solution is executed with error 'signed integer overflow' on the line 22
    }
    return sum;
}

void solve() {
    ll n, c; cin >> n >> c;
    vll v(n);
    invec(v, n);

    ll l = 0, r = sqrt(c/n) + 2;  // Adjusted r to a more realistic limit
    while(l < r){
        ll w = l + (r - l) / 2;
        ll sum = f(w, n, v);
        if(sum >= c){
            r = w;
        } else {
            l = w + 1;
        }
    }
    cout << l/2 << endl;
}

int32_t main() {
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}