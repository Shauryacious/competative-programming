#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    int dp[101][101][101];
    int solve(string& s1, string& s2, string& s3, int i, int j, int k){
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(i == n1 || j == n2 || k == n3) {
            return 0; // Base case: if any string is exhausted, LCS is 0
        }
        if(dp[i][j][k] != -1) { // Check if already computed
            return dp[i][j][k];
        }

        if(s1[i] == s2[j] && s2[j] == s3[k]){
            dp[i][j][k] = 1 + solve(s1, s2, s3, i + 1, j + 1, k + 1); 
        }
        else{
            dp[i][j][k] = max({solve(s1, s2, s3, i + 1, j, k), 
                               solve(s1, s2, s3, i, j + 1, k), 
                               solve(s1, s2, s3, i, j, k + 1)});
        }

        return dp[i][j][k]; // Return the computed LCS length
    }
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};
