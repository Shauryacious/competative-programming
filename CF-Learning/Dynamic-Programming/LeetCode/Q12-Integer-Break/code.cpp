#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007

class Solution {
    int dp[101];
public:
    int integerBreak(int num) {
        
        auto f = [&](int n, auto && f) -> int{
            if(n <= 2) return 1;
            if(n == 3) return 2;

            if(dp[n] != -1) return dp[n];

            int ans = 1;
            for(int i = 1; i<= (n-1); i++){
                // IMPORTANT: Use max(n - i, f(n - i, f)) to ensure we are considering the maximum product
                // For ex : in case of n = 10 - 7 = 3
                // (10 - 7) = 3      &      dp[(10 - 7)] = dp[3] = 2
                // So, we should take max(3, 2) = 3

                int curr = i * max(n - i, f(n - i, f));
                ans = max(ans, curr);
            }

            return dp[n] = ans;
        };

        memset(dp, -1, sizeof(dp));

        return f(num, f);
    }
};