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
#define vvpii vector<vpii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define ff first
#define ss second


//NOTE:
// r1 = r2 = r -> both robots are at the same row


class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();  

        int dp[75][75][75];
        memset(dp, -1, sizeof(dp)); 

        auto f = [&](int r, int c1, int c2, auto && f) -> int {
            if(r == n) return 0; // no more rows to pick cherries

            if(dp[r][c1][c2] != -1) return dp[r][c1][c2]; 

            int ans = 0;

            int cherries = 0;
            if(c1 == c2) {
                cherries = g[r][c1]; // both robots are at the same cell
            } else {
                cherries = g[r][c1] + g[r][c2]; // both robots are at different cell
            }

            for(int dc1 = -1; dc1 <= 1; dc1++) {
                for(int dc2 = -1; dc2 <= 1; dc2++){
                    int nc1 = c1 + dc1;
                    int nc2 = c2 + dc2;

                    if(nc1 < 0 || nc1 >= m) continue; // out of bounds for robot 1
                    if(nc2 < 0 || nc2 >= m) continue; // out of bounds for robot 2

                    ans = max(ans, cherries + f(r + 1, nc1, nc2, f)); // move to next row
                }
            }

            return dp[r][c1][c2] = ans; 
        };

        int ans = 0;
        ans = f(0, 0, m - 1, f); 

        return ans;
    }
};