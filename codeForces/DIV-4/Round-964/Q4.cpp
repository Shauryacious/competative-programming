#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
// #include <bits/stdc++.h>

using namespace std;

// Speed up input and output
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// Typedefs for convenience
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    string a, b;
    cin >> a >> b;
    ll i = 0, j = 0;
    ll n = a.length(), m = b.length();
    
    // Match characters in a and b, considering '?' as a wildcard
    while (i < n && j < m) {
        if (a[i] == b[j] || a[i] == '?') {
            a[i] = b[j];  // Replace '?' with corresponding character in b
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    // If b is not fully matched, output "NO"
    if (i >= n && j < m) {
        cout << "NO" << endl;
    } else {
        // Replace remaining '?' in a with 'a'
        for (ll i = 0; i < n; i++) {
            if (a[i] == '?') a[i] = 'a';
        }
        cout << "YES" << endl;
        cout << a << endl;
    }
}

int32_t main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}