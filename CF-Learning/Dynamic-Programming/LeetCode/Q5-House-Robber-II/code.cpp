#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    int dp[101];
    // dp[i] = maximum amount of money that can be robbed from houses starting from index i
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // Only one house

        auto f = [&](int i, vii& a, auto && f) -> int {
            if(i >= a.size()) return 0;

            if(dp[i] != -1) return dp[i];

            int take = a[i] + f(i+2, a, f);
            int skip = f(i+1, a, f);

            return dp[i] = max(take, skip);
        };

        int ans = 0;

        // Case 1: Rob the first house and not the last house
        memset(dp, -1, sizeof(dp));
        vii a(nums.begin(), nums.end() - 1); // nums[0 ... n-2]
        int ans1 = f(0, a, f);

        // Case 2: Rob the last house and not the first house
        memset(dp, -1, sizeof(dp));
        vii b(nums.begin() + 1, nums.end()); // nums[1 ... n-1]
        int ans2 = f(0, b, f);

        return max(ans1, ans2);
    }
};
