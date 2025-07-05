class Solution {
  public:
    bool isSubsetSum(vector<int>& a, int target) {
        int n = a.size();
        int m = target;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 && j==0){
                    dp[i][j] = true; // can we get a sum of 0(col), using the ele 0(row) 
                }
                else if(i == 0){
                    dp[i][j] = false; // what all sum can we get from the element 0(i.e. the empty subset) -> no sum > 0 i.e. false
                }
                else if(j == 0){
                    dp[i][j] = true; // can we get a sum of 0 using subset from the prefix of length i
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    if(j-a[i-1] >= 0){
                        dp[i][j] = (dp[i][j] || dp[i-1][j-a[i-1]]);
                    }
                }
            }
        }
        
        return dp[n][target];
    }
};