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
#define INF 1e18

class Solution {
public:
    ll maximumProfit(vector<int>& p, int k) {
        int n = p.size();

        ll dp[1001][2][2][501];
        memset(dp, -1, sizeof(dp));

        // hs = holding stock
        // hss = holding short selling stock
        // cap - number of transactions allowed

        auto f = [&](int i, int hs, int hss, int cap, auto && f) -> ll {
            if(dp[i][hs][hss][cap] != -1) {
                return dp[i][hs][hss][cap];
            }

            if(i == n) { // we can make any profit at the end
                if(hs || hss) return -INF;
                return 0;
            }

            if(cap == 0) { // no more transactions allowed
                return 0;
            }

            if(hs && hss) return -INF;

            ll profit = 0;

            if(hs){ //if holding stock
                // we can either sell the stock or not
                ll sell = p[i] + f(i + 1, 0, hss, cap - 1, f); 

                ll notSell = f(i + 1, hs, hss, cap, f);

                profit = max(max(sell, notSell), profit);
            }
            else if(hss) { // if holding short selling stock
                // we can either buy the stock or not
                ll sellShort = -p[i] + f(i + 1, hs, 0, cap - 1, f);

                ll notSellShort = f(i + 1, hs, hss, cap, f);

                profit = max(max(sellShort, notSellShort), profit);
            }
            else { // if not holding any stock
                // we can either buy the stock or short sell the stock or not do anything
                ll buy = -p[i] + f(i + 1, 1, hss, cap, f); // buy stock
                ll shortSell = p[i] + f(i + 1, hs, 1, cap, f); // short sell stock
                ll notAnything = f(i + 1, hs, hss, cap, f); // do nothing

                profit = max(max(buy, shortSell), notAnything);
            }

            return dp[i][hs][hss][cap] = profit; 
        };

        // Start with no stock, no short selling stock, and k transactions allowed
        return f(0, 0, 0, k, f);
    }
};