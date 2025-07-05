class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Handle empty input
        
        // dp[i] = {length of LIS ending at i, count of LIS of that length}
        vector<pair<int, int>> dp(n, {1, 1});

        for (int i = 0; i < n; i++) {
            int prev_max = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // Increasing subsequence
                    prev_max = max(prev_max, dp[j].first);
                }
            }

            int count = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if(dp[j].first == prev_max){
                        count += dp[j].second;
                    }
                }
            }

            // If no valid subsequence before i, count should be 1
            dp[i] = {prev_max + 1, count > 0 ? count : 1};
        }

        int max_length = 0;
        for (int i = 0; i < n; i++) {
            max_length = max(max_length, dp[i].first);
        }
        int max_count = 0;
        for (int i = 0; i < n; i++) {
            if(dp[i].first == max_length){
                max_count += dp[i].second;
            }
        }

        return max_count;
    }
};
