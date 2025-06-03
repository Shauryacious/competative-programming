#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
class Solution {
  public:
    int uniquePaths(vector<vector<int>> &g) {
        ii n = g.size(), m = g[0].size();
        vvii dp(n, vii(m, 0));
        if(g[0][0] == 1 || g[n-1][m-1] == 1) return 0; // If start or end is blocked, return 0
        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(g[i][j] == 1) continue; // If cell is blocked, skip
                if(i > 0) dp[i][j] += dp[i-1][j]; // From top
                if(j > 0) dp[i][j] += dp[i][j-1]; // From left
            }
        }

        return dp[n-1][m-1]; // Return the number of unique paths to the bottom-right corner
    }
};