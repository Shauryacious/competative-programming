class Solution {
    const int INF = 1e9;
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = minimum no of jumps required to reach last stone from the ith stone
        vector<int> dp(n, INF);
        // Base case
        dp[n-1] = 0; // 0 no of jumps are required to reach last stone from the last stone

        for(int i=n-2; i>=0; i--){
            if(nums[i] == 0){
                dp[i] = INF;
            }
            else{
                int val = nums[i];
                for(int j=1; j<=val; j++){
                    if(i+j < n){
                        dp[i] = min(dp[i], dp[i+j] + 1);
                    }
                }
            }
        }


        return dp[0];

    }
};