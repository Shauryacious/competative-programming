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
    int minFallingPathSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        vvll dp(n, vector<ll>(m, -1));


        auto f = [&](int i, int j, auto && f) -> ll {
            if(i == n) return 0;

            if(j < 0 || j >= m) return INF;

            if(dp[i][j] != -1) return dp[i][j];

            ll ans = INF;

            ans = min(ans, (ll)g[i][j] + f(i + 1, j - 1, f));
            ans = min(ans, (ll)g[i][j] + f(i + 1, j, f));
            ans = min(ans, (ll)g[i][j] + f(i + 1, j + 1, f));

            return dp[i][j] = ans;
        };

        ll ans = INF;
        for(int j = 0; j < m; j++){
            ans = min(ans, f(0, j, f));
        }
        return (int)ans;
    }
};