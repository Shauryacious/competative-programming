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
    vll a(n);
    bool flag = false;
    cin>>a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] != a[i-1]) flag = true;
    }

    if (!flag) {
        cout << -1 << endl;
        return;
    }
    vll b;

    sort(a.begin(), a.end());
    b.push_back(a[0]);
    for(int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            b.push_back(a[i]);
        } else {
            break;
        }
    }

    vll c(a.begin() + b.size(), a.end());

    cout<<b.size() << " " << c.size() << endl;
    for(auto val : b) cout << val << " ";
    cout << endl;
    for(auto val : c) cout << val << " ";
    cout << endl;
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