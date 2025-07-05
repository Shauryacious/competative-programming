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
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n = val.size();

        vvii dp(n + 1, vii(W + 1, -1));
        
        auto f = [&](int i, int currwt, auto&& f) -> int {
            if(currwt > W) return -INF; 

            if(i == n) return 0;

            if(dp[i][currwt] != -1) return dp[i][currwt];

            // Include the current item
            // Notice how we didnt move to the next item
            // to allow for unbounded knapsack
            int include = val[i] + f(i, currwt + wt[i], f);

            // Exclude the current item
            int exclude = f(i + 1, currwt, f);

            return dp[i][currwt] = max(include, exclude);
        };
        
        int ans = f(0, 0, f);

        return ans;
    }
};