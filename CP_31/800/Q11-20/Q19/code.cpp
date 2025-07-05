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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    int countn1 = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == -1) {
            countn1++;
        }
    }

    if (sum >= 0) {
        if (countn1 % 2 == 0) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        int needed_flips = (-sum + 1) / 2;
        countn1 -= needed_flips;
        if (countn1 % 2 == 0) {
            cout << needed_flips << endl;
        } else {
            cout << needed_flips + 1 << endl;
        }
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