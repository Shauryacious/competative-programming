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
    int cutRod(vector<int> &a) {
        int n = a.size();

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int curr, auto && f) -> int {
            if(curr > n) return -INF; // Impossible to cut further
            if(i == n){
                if(curr == n) return 0;
                return -INF; // Not possible to cut further
            }

            if(dp[i][curr] != -1) return dp[i][curr];

            int ans = 0;

            // Take -> dont move the pointer -> unbounded knapsack
            ans = max(ans, a[i] + f(i, curr + i + 1, f));

            // Not take
            ans = max(ans, f(i + 1, curr, f));

            return dp[i][curr] = ans;
        };
        
        return f(0, 0, f);
    }
};