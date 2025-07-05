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
    int coinChange(vector<int>& a, int t) {
        int n = a.size();

        ll dp[20][10005];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, ll curr, auto && f) -> ll {
            if(curr < 0) return INF;
            if(i == n) {
                return curr == 0 ? 0 : INF;
            }

            if(dp[i][curr] != -1) return dp[i][curr];

            
            ll ans = INF;

            //Include the coin
            ans = min(ans, 1 + f(i, curr - a[i], f));

            //Exclude the coin
            ans = min(ans, f(i + 1, curr, f));

            return dp[i][curr] = ans;
        };

        ll ans = f(0, t, f);
        return ans == INF ? -1 : (int)ans;
    }
};