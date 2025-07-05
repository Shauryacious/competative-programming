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
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        //Edge case: If the starting or ending cell is an obstacle, return 0
        if(g[0][0] == 1 || g[n-1][m-1] == 1) return 0;

        int dp[101][101];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int j, auto && f) -> int {
            if(i == n-1 && j == m-1) return 1;
            if(i >= n || j >= m) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int ans = 0;

            // If the current cell is an obstacle, return 0
            if(i+1 < n && g[i+1][j] == 0){
                ans += f(i + 1, j, f);
            }

            // If the current cell is an obstacle, return 0
            if(j+1 < m && g[i][j+1] == 0){
                ans += f(i, j + 1, f); 
            }

            return dp[i][j] = ans;
        };

        return f(0, 0, f);
    }
};