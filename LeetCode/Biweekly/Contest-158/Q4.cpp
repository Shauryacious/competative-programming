#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pb push_back
#define MOD 1000000007

class Solution {
    ii getMask(ii x) {
        ii m = 0;
        while (x) {
            ii d = x % 10;
            if (m & (1 << d)) return -1;
            m |= (1 << d);
            x /= 10;
        }
        return m;
    }

    ii getValue(vii& nodes, vii& vals, vii& digitmask) {
        vii dp(1 << 10, -1);
        dp[0] = 0;

        for (auto u : nodes) {
            ii m = digitmask[u];
            if (m == -1) continue;
            ii v = vals[u];

            for (ii s = (1 << 10) - 1; s >= 0; --s) {
                if (dp[s] == -1) continue;
                if ((s & m) == 0) {
                    dp[s | m] = max(dp[s | m], dp[s] + v);
                }
            }
        }

        ii mx = 0;
        for (auto x : dp) mx = max(mx, x);
        return mx;
    }

public:
    ii goodSubtreeSum(vii& vals, vii& par) {
        ii n = vals.size();

        vvii g(n);
        for (ii i = 1; i < n; ++i) {
            g[par[i]].pb(i);
        }

        vii digitmask(n);
        for (ii i = 0; i < n; ++i) {
            digitmask[i] = getMask(vals[i]);
        }

        vii maxScore(n);

        function<vii(ii)> dfs = [&](ii u) {
            vii subtree;
            subtree.pb(u);

            for (auto v : g[u]) {
                vii sub = dfs(v);
                for (auto x : sub) subtree.pb(x);
            }

            maxScore[u] = getValue(subtree, vals, digitmask);
            return subtree;
        };

        dfs(0);

        ii sum = 0;
        for (auto x : maxScore) sum = (sum + x) % MOD;
        return sum;
    }
};
