// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<random>
#include<string>
#include<functional>
#include<iomanip>
#include<limits>
#include<array>
#include<utility>
#include<functional>
#include<iterator>
#include<cstring>

using namespace std;


#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e9


class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();

        int dp[1005][2][105];
        memset(dp, -1, sizeof(dp));

        // buy determines whether we are allowed to buy stock or not
        // i.e. whether we are holding stock or not

        // cap - determines the number of transactions allowed

        auto f = [&](int i, int buy, int cap, auto&& f) -> int {
            if (i >= n) return 0;

            if (cap == 0) return 0; // no transactions left

            if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
            
            int profit = 0;

            if(buy){ // if not holding stock
                int buyStock = -p[i] + f(i + 1, 0, cap, f); // buy stock

                int dontBuyStock = f(i + 1, 1, cap, f); // dont buy stock

                profit = max(max(profit, buyStock), dontBuyStock);
            }
            else{ // if holding stock -> Sell or dont sell
                int sellStock = p[i] + f(i + 1, 1, cap - 1, f); // sell stock

                int dontSellStock = f(i + 1, 0, cap, f); // dont sell stock 

                profit = max(max(profit, sellStock), dontSellStock);
            }

            return dp[i][buy][cap] = profit; // store the result in dp array
        };

        return f(0, 1, k, f); 
    }
};