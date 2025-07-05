#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007

class Solution {
    int dp[100001];
  public:
    int countWays(int n, int m) {
        if(n < m) return 1;
        if(n == m) return 2;

        auto f = [&](int n, auto && f) -> int {
            if(n < 0) return 0;
            if(n == 0) return 1;
            if(dp[n] != -1) return dp[n];

            int ans = 0;
            ans += f(n - m, f); // place m-length tile
            ans %= MOD;
            ans += f(n - 1, f); // place 1-length tile
            ans %= MOD;

            return dp[n] = ans;
        };

        memset(dp, -1, sizeof(dp));
        return f(n, f);
    }
};
