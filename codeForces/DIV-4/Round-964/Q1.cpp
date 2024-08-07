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


void solve() {
    int n; cin >> n;
    string s = to_string(n);
    int ans = (s[0] - '0') + (s[1] - '0'); // Corrected the logic to convert char to int
    cout << ans << endl;
}

int32_t main() {
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}