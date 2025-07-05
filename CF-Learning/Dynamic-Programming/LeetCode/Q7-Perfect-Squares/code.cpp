#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    int INF = 1e9;
    vii v;
    int dp[10001];
public:
    int numSquares(int num) {

        for(int i=1; i<=100; i++){
            int x = i*i;
            v.pb(x);
        }

        auto f = [&](int n, auto && f) -> int {
            if(n == 0) return 0;
            if(n <= 0) return INF;

            if(dp[n] != -1) return dp[n];

            int ans = INF;
            for(auto p : v){
                ans = min(ans, 1 + f(n-p, f));
            }

            return dp[n] = ans;
        };

        memset(dp, -1, sizeof(dp));

        int ans = f(num, f);
        return ans;
    }
};