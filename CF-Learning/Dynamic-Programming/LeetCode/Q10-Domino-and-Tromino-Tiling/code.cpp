#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007

class Solution {
    int dp[1001];
public:
    int numTilings(int num) {
        auto f = [&](int n, auto && f) -> int{
            if(n == 1) return 1;
            if(n == 2) return 2;
            if(n == 3) return 5;

            if(dp[n] != -1) return dp[n];

            int ans = 0;
            ans += 2 * f(n - 1, f);
            ans %= MOD;
            ans += f(n-3, f);
            ans %= MOD;

            return dp[n] = ans;
        };

        memset(dp, -1, sizeof(dp));

        int ans = f(num, f);
        ans %= MOD;

        return ans;
    }
};