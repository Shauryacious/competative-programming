// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<random>
#include<string>
#include<functional>
#include<iomanip>
#include<limits>
#include<array>
#include<utility>
#include<functional>
#include<iterator>
#include<cstring>

using namespace std;


#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e9

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        vvll dp(n, vll(m, -1));

        auto f = [&](int i, int j, auto && f) -> ll {
            if(i == n-1 && j == m-1) return g[i][j];
            if(i >= n || j >= m) return INF;

            if(dp[i][j] != -1) return dp[i][j];

            ll ans = INF;

            // down
            ans = min(ans, (ll)(g[i][j]) + f(i + 1, j, f));

            // right
            ans = min(ans, (ll)(g[i][j]) + f(i, j + 1, f));

            return dp[i][j] = ans;
        };

        ll ans = f(0, 0, f);

        return (int)ans;
    }
};