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
    string s; cin>>s;
    int n = s.size();

    int n0=0, n1=0;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            n0++;
        }
        else{
            n1++;
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            if(n1 > 0){
                n1--;
                count++;
            }
            else{
                break;
            }
        }
        else if(s[i] == '1'){
            if(n0 > 0){
                n0--;
                count++;
            }
            else{
                break;
            }
        }
    }

    cout<<n-count<<endl;
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