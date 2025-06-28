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
    int paintWalls(vector<int>& c, vector<int>& t) {
        int n = c.size();

        int dp[505][505];

        auto f = [&](int i, int rem, auto && f) -> int {
            if(i == n){
                if(rem <= 0) return 0;
                return INF;
            }

            if(rem <= 0) rem = 0;

            if(dp[i][rem] != -1) return dp[i][rem];

            int ans = INF;
            //paint the current wall
            ans = min(ans, c[i] + f(i + 1, rem - t[i] - 1, f));

            //don't paint the current wall
            ans = min(ans, f(i + 1, rem, f));

            return dp[i][rem] = ans;
        };

        memset(dp, -1, sizeof(dp));
        int ans = f(0, n, f);
        return ans;
    }
};