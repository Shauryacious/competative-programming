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
    string s; cin >> s;
    int c0 = 0, c1 = 0;
    for (char ch : s) {
        if (ch == '0') c0++;
        else c1++;
    }
    int ans = min(c0, c1);
    if (ans % 2 == 0) cout << "NET" << endl;
    else cout << "DA" << endl;
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