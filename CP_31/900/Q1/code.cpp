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
    int a, b; cin>>a>>b;
    int xk, yk; cin>>xk>>yk;
    int xq, yq; cin>>xq>>yq;

    set<pair<int, int>> s;

    s.insert({xk+a, yk+b});
    s.insert({xk+a, yk-b});
    s.insert({xk-a, yk+b});
    s.insert({xk-a, yk-b});
    s.insert({xk+b, yk+a});
    s.insert({xk+b, yk-a});
    s.insert({xk-b, yk+a});
    s.insert({xk-b, yk-a});


    int count = 0;

    if(s.find({xq+a, yq+b}) != s.end()){ 
        s.erase({xq+a, yq+b});
        count++;
    }
    if(s.find({xq+a, yq-b}) != s.end()){ 
        s.erase({xq+a, yq-b});
        count++;
    }
    if(s.find({xq-a, yq+b}) != s.end()){ 
        s.erase({xq-a, yq+b});
        count++;
    }
    if(s.find({xq-a, yq-b}) != s.end()){ 
        s.erase({xq-a, yq-b});
        count++;
    }
    if(s.find({xq+b, yq+a}) != s.end()){ 
        s.erase({xq+b, yq+a});
        count++;
    }
    if(s.find({xq+b, yq-a}) != s.end()){ 
        s.erase({xq+b, yq-a});
        count++;
    }
    if(s.find({xq-b, yq+a}) != s.end()){ 
        s.erase({xq-b, yq+a});
        count++;
    }
    if(s.find({xq-b, yq-a}) != s.end()){ 
        s.erase({xq-b, yq-a});
        count++;
    }
    cout<<count<<endl;
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