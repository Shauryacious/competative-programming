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
    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();

        int off = 1000;

        int dp[25][2005];

        auto f = [&](int i, int sm, auto && f) -> int {
            if(i == n) {
                return sm == t ? 1 : 0;
            }

            if(dp[i][sm + off] != -1) {
                return dp[i][sm + off];
            }

            // Include the current element with a positive sign
            int inc = f(i + 1, sm + a[i], f);

            // Include the current element with a negative sign
            int exc = f(i + 1, sm - a[i], f);

            return dp[i][sm + off] = (inc + exc);
        };

        memset(dp, -1, sizeof(dp));

        return f(0, 0, f);
    }
};