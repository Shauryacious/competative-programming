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
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

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

}

int32_t main() {
    fastio();
    ll n;
    cin >> n;
    vll a(n);
    invec(a, n);

    vll v1, v2;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) v1.push_back(a[i]);
        else v2.push_back(a[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());

    // Ensure there are elements in v1 and v2 before accessing them
    ll diff1 = v1.empty() ? LLONG_MAX : abs(v1[0] - 0);
    ll diff2 = v2.empty() ? LLONG_MAX : abs(v2[0] - 0);

    cout << min(diff1, diff2) << endl;
    return 0;
}