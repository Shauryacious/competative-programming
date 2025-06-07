#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    int dp[10001];
    int INF = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        auto f = [&](int amt, auto && f) -> int {
            if (amt < 0) return INF; // invalid
            if (amt == 0) return 0;  // no coins needed
            if (dp[amt] != -1) return dp[amt];

            int ans = 1e9;
            for (auto c : coins) {
                ans = min(ans, 1 + f(amt - c, f));
            }

            return dp[amt] = ans;
        };

        memset(dp, -1, sizeof(dp));
        int ans = f(amount, f);
        return ans >= 1e9 ? -1 : ans;
    }
};
