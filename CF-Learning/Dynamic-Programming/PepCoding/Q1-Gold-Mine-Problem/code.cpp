class Solution {
const int INF = 1e9;
  public:
    int maxGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // State: 
        // dp[i][j] = maximum amount of gold that he can collect from (i, j) to the last column
        
        // Base Case: 
        // last column --> dp[row][last col] = grid[row][last col]
        
        vector<vector<int>> dp(m, vector<int>(n, -INF));
        
        for(int i = 0; i < m; i++){
            dp[i][n - 1] = grid[i][n - 1];
        }
        
        for(int j = n - 2; j >= 0; j--){ // Corrected this line to iterate over columns
            for(int i = 0; i < m; i++){
                if(i == 0){
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + grid[i][j];
                }
                else if(i == m - 1){
                    dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + grid[i][j];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j + 1], max(dp[i][j + 1], dp[i + 1][j + 1])) + grid[i][j];
                }
            }
        }
        
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        int mx = INT_MIN;
        for(int i = 0; i < m; i++){
            mx = max(mx, dp[i][0]);
        }
        
        return mx;
    }
};
