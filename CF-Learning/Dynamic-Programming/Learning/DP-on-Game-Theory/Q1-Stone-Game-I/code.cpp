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
    bool stoneGame(vector<int>& a) {
        int n = a.size();

        int dp[505][505][2];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int j, int turn, auto&& f) -> int {
            if (i > j) return 0;

            if (dp[i][j][turn] != -1) return dp[i][j][turn];

            if (turn) { // if its
                int pickLeft = a[i] + f(i+1, j, 0, f);
                int pickRight = a[j] + f(i, j-1, 0, f);
                return dp[i][j][turn] = max(pickLeft, pickRight);
            }
            else {
                int pickLeft = f(i+1, j, 1, f);
                int pickRight = f(i, j-1, 1, f);
                return dp[i][j][turn] = min(pickLeft, pickRight);
            }
        };

        int sm = accumulate(all(a), 0);
        int alice = f(0, n-1, 1, f);
        return alice > sm - alice;
    }
};
