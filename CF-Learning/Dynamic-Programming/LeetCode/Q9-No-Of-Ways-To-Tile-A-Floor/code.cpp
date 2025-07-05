#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007


class Solution {
    int dp[100001];
  public:
    int numberOfWays(int n) {
        auto f = [&](int rem, auto && f) -> int {
            if (rem == 0) return 1;
            if (rem < 0) return 0;

            if (dp[rem] != -1) return dp[rem];

            int ans = 0;
            ans += f(rem - 1, f); // Place a 2x1 tile
            ans += f(rem - 2, f); // Place two 1x2 tiles
            ans %= MOD;

            return dp[rem] = ans;
        };

        memset(dp, -1, sizeof(dp));
        int ans = f(n, f);
        return ans;
    }
};