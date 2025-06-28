class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();

        int dp[50005][2];
        memset(dp, -1, sizeof(dp));

        // buy - determines whether we are allowed to buy stock or not
        // i.e. whether we are holding stock or not

        auto f = [&](int i, int buy, auto&& f) -> int {
            if (i >= n) return 0;

            if(dp[i][buy] != -1) return dp[i][buy];
            
            int profit = 0;

            if(buy){ // if not holding stock
                int buyStock = -p[i] + f(i + 1, 0, f); // buy stock

                int dontBuyStock = f(i + 1, 1, f); // dont buy stock

                profit = max(max(profit, buyStock), dontBuyStock);
            }
            else{ // if holding stock -> Sell or dont sell
                int sellStock = p[i] + f(i + 1, 1, f) - fee; // sell stock and pay fee

                int dontSellStock = f(i + 1, 0, f); // dont sell stock

                profit = max(max(profit, sellStock), dontSellStock);
            }

            return dp[i][buy] = profit;
        };

        return f(0, 1, f); // start with buying stock
    }
};