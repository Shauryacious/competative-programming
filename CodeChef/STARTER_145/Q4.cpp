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


    // if (n == 1) {
    //     if (s[0] == '0') {
    //         cout << "1" << endl;
    //     } else {
    //         cout << "0" << endl;
    //     }
    //     return;
    // }

    // if (n == 2) {
    //     if (s[0] == '0' && s[1] == '0') {
    //         cout << "1" << endl;
    //     } else if (s[0] == '1' && s[1] == '1') {
    //         cout << "0" << endl;
    //     } else {
    //         cout << "1" << endl;
    //     }
    //     return;
    // }

void solve() {
    ll n; 
    cin >> n;
    string s; 
    cin >> s;

    ll o = 0, x = 0;
    bool inZeroSegment = false, inOneSegment = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (!inZeroSegment) {
                o++;
                inZeroSegment = true;
            }
            inOneSegment = false;
        } else {
            if (!inOneSegment) {
                x++;
                inOneSegment = true;
            }
            inZeroSegment = false;
        }
    }

    cout << "o: " << o << " x: " << x << endl;

    if (x > o) {
        cout << "0" << endl;
        return;
    } else if (x == o) {
        ll minZeroSegmentLength = INT_MAX;
        ll currentSegmentLength = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                currentSegmentLength++;
            } else {
                if (currentSegmentLength > 0) {
                    minZeroSegmentLength = min(minZeroSegmentLength, currentSegmentLength);
                    currentSegmentLength = 0;
                }
            }
        }

        if (currentSegmentLength > 0) {
            minZeroSegmentLength = min(minZeroSegmentLength, currentSegmentLength);
        }

        cout << minZeroSegmentLength << endl;
        return;
    } else {
        ll totalZeros = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                totalZeros++;
            }
        }

        cout << totalZeros << endl;
        return;
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