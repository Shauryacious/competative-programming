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

// Functions
template <typename T>
T sumvec(const vector<T>& vec) {
    T sum = 0;
    for (auto val : vec) sum += val;
    return sum;
}

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;

    unordered_map<char, int> mp;

    for(int i=0; i<n; i++){
        mp[s[i]]++;
    }

    int odd = 0;

    for(auto it : mp){
        if(it.second%2 != 0){
            odd++;
        }
    }

    if(odd >= k){
        if(odd-k <= 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
        cout<<"YES\n";
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