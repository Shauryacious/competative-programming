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

void solve() {
    ll n, m; cin>>n>>m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }


    // dp[i][j] = min sum path from (i, j) to (n-1, m-1)
    // dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1])

    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    // Base case for the last element
    dp[n-1][m-1] = grid[n-1][m-1];

    for(ll i=n-1; i>=0; i--){
        for(ll j=m-1; j>=0; j--){
            if(i==n-1 && j==m-1) continue;
            if(i==n-1){
                dp[i][j] = grid[i][j] + dp[i][j+1];
            }else if(j==m-1){
                dp[i][j] = grid[i][j] + dp[i+1][j];
            }else{
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
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
