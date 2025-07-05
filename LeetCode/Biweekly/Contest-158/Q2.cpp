#define ii int
#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define vvii vector<vector<int>>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007

class Solution {
public:
    ll maximumProfit(vii &a, ii k) {
        ii n = a.size();
        if (n < 2 || k == 0) return 0LL;

        vvll dp(k + 1, vll(n, 0LL));

        for (ii t = 1; t <= k; ++t) {
            ll best1 = dp[t - 1][0] - a[0];
            ll best2 = dp[t - 1][0] + a[0];

            for (ii i = 1; i < n; ++i) {
                ll noOp = dp[t][i - 1];
                ll buySell = a[i] + best1;
                ll sellBuy = -a[i] + best2;

                dp[t][i] = max({noOp, buySell, sellBuy});

                // Move updates AFTER using dp[t][i], so no overlap on day i
                best1 = max(best1, dp[t - 1][i - 1] - a[i]);
                best2 = max(best2, dp[t - 1][i - 1] + a[i]);
            }
        }

        return dp[k][n - 1];
    }
};
