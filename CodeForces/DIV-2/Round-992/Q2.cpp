// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Codechef: https://www.codechef.com/users/shauryacious27

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <climits>

using namespace std;
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAX_N = 100000;
vector<int> min_operations(MAX_N + 1);

void precompute() {
    vector<ll> a(32); // Since a[i] grows exponentially, we only need up to 32 terms
    a[0] = 0;
    a[1] = 1;
    a[2] = 4;
    for (ll i = 3; i <= 31; i++) {
        a[i] = (a[i-1] + 1) * 2;
    }

    // Precompute minimum operations for all n <= MAX_N
    int position = 1;
    for (int n = 1; n <= MAX_N; n++) {
        while (position <= 31 && a[position] < n) {
            position++;
        }
        min_operations[n] = position;
    }
}

void solve() {
    ll n; 
    cin >> n;
    cout << min_operations[n] << "\n";
}

int main() {
    fastio();
    precompute();
    ll t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
