class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool conatins1 = false;

        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    grid[i][j] = 1;
                    conatins1 = true;
                }
            }
        }

        int mxside = 0;
        if(conatins1) mxside = 1;


        vector<vector<int>> dp(m, vector<int>(n, 0));


        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = grid[i][j];
                }
                else if(i == m-1){
                    dp[i][j] = grid[i][j];
                }
                else if(j == n-1){
                    dp[i][j] = grid[i][j];
                }
                else{
                    if(grid[i][j] == 0){
                        dp[i][j] = 0;
                    }
                    else if(grid[i][j] == 1){
                        dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])); // minimum of right, down and diagonal
                        dp[i][j] += 1;
                        mxside = max(mxside, dp[i][j]);
                    }
                
                }
            }
        }
        return mxside*mxside;
    }
};