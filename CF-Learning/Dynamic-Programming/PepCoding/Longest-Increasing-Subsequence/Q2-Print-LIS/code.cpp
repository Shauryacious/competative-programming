class Solution {
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        // state: 
        // dp[i] = max length of a subsequence s.t.
        // it ends with ele a[i]
        // also it is increasing in nature
        
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; i++) {
            int maxx = 0;
            for(int j = 0; j < i; j++) {
                if(a[j] < a[i]) { // increasing in nature
                    maxx = max(maxx, dp[j]);
                }
            }
            dp[i] = maxx + 1;
        }
        
        int max_val = 0;
        int max_idx = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] > max_val) {
                max_val = dp[i];
                max_idx = i;
            }
        }
        
        // Now, we need to find the actual subsequence
        // We will use BFS for this
        queue<pair<int, vector<int>>> q;
        q.push({max_idx, {}});
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int idx = p.first;
            vector<int> ans_so_far = p.second;
            ans_so_far.push_back(a[idx]);
            
            if(dp[idx] == 1) { // Base case: smallest subsequence length is 1
                reverse(ans_so_far.begin(), ans_so_far.end()); // Reverse the order
                return ans_so_far;
            }
            
            for(int i = 0; i < idx; i++) {
                if(dp[i] == dp[idx] - 1 && a[i] < a[idx]) { // Corrected comparison and condition
                    q.push({i, ans_so_far});
                }
            }
        }
        return {};
    }
};
