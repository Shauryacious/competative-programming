#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007

class Solution {
    int dp[5001][10];
public:
    int knightDialer(int n) {
        vvii adj(10);
        adj[0] = {4, 6};
        adj[1] = {6, 8};
        adj[2] = {7, 9};    
        adj[3] = {4, 8};
        adj[4] = {0, 3, 9};
        adj[5] = {};
        adj[6] = {0, 1, 7};
        adj[7] = {2, 6};
        adj[8] = {1, 3};
        adj[9] = {2, 4};


        auto f = [&](int num, int rem, auto && f) -> int {
            if(rem == 0) return 1;

            if(dp[rem][num] != -1) return dp[rem][num];

            int ans = 0;
            for(int next : adj[num]) {
                ans += f(next, rem - 1, f);
                ans %= MOD;
            }
            return dp[rem][num] = ans;
        };

        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i <= 9; i++) {
            ans += f(i, n - 1, f);
            ans %= MOD;
        }

        return ans;
    }
};