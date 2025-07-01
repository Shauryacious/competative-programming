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
    int numWays(int steps, int n) {

        int dp[505][505];
        memset(dp, -1, sizeof(dp));    

        auto f = [&](int rem, int curr, auto && f) -> int {
            if(curr < 0 || curr >= n) return 0;
            if(rem == 0){
                if(curr == 0) return 1;
                return 0;
            }

            if(dp[rem][curr] != -1) return dp[rem][curr];

            int ans = 0;

            // Move left
            ans += f(rem - 1, curr - 1, f);
            ans %= MOD;

            // Move right
            ans += f(rem - 1, curr + 1, f);
            ans %= MOD;

            // Stay in place
            ans += f(rem - 1, curr, f);
            ans %= MOD;

            return dp[rem][curr] = ans;
        };

        return f(steps, 0, f);
    }
};