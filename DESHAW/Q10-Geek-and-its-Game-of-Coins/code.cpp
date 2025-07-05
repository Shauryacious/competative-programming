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
    int findWinner(int n, int x, int y) {

        int dp[100005];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int rem, auto &&f) -> int {
            if (rem == 0) return 0;

            if (dp[rem] != -1) return dp[rem];

            int ans = 0;

            if (rem >= 1 && f(rem - 1, f) == 0) ans |= 1;
            if (rem >= x && f(rem - x, f) == 0) ans |= 1;
            if (rem >= y && f(rem - y, f) == 0) ans |= 1;

            return dp[rem] = ans;
        };

        return f(n, f);
    }
};
