#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    int dp[101];
    // dp[i] = maximum amount of money that can be robbed from houses starting from index i
public:
    int rob(vector<int>& a) {
        int n = s.size();

        memset(dp, -1, sizeof(dp)); 
        auto f = [&](int i){
            if(i >= n-1) return 0;

            if(dp[i] != -1) return dp[i];

            int take = a[i] + f(i+2);
            int skip = f(i+1);

            return dp[i] = max(take, skip);
        };

        return f(0);
    }
};