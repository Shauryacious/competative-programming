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
    int profitableSchemes(int m, int mnp, vector<int>& g, vector<int>& p) {
        int n = g.size();

        int dp[105][105][105];

        auto f = [&](int i, int cm, int cp, auto && f) -> int {
            if(i == n){
                if(cp >= mnp && cm <= m) return 1;
                return 0;
            }

            cp = min(cp, mnp); // Ensure cp does not exceed mnp

            if(dp[i][cm][cp] != -1) return dp[i][cm][cp];

            int ans = 0;
            // not taking the current scheme
            ans += f(i + 1, cm, cp, f);
            ans %= MOD;

            // taking the current scheme
            if(cm + g[i] <= m) {
                ans += f(i + 1, cm + g[i], cp + p[i], f);

                ans %= MOD;
            }

            return dp[i][cm][cp] = ans % MOD;
        };

        memset(dp, -1, sizeof(dp));

        return f(0, 0, 0, f);
    }
};