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
    int maxSatisfaction(vector<int>& a) {
        int n = a.size();
        sort(all(a));

        int dp[505][505];
        
        auto f = [&](int i, int tc, auto && f) -> int {
            if(i == n) {
                return 0;
            }

            if(dp[i][tc] != -1) {
                return dp[i][tc];
            }

            int ans = 0;

            // Include the current dish
            ans = max(ans, (((tc + 1) * a[i]) + f(i + 1, tc + 1, f)));

            // Exclude the current dish
            ans = max(ans, f(i + 1, tc, f));

            return dp[i][tc] = ans;
        };

        memset(dp, -1, sizeof(dp));
        return f(0, 0, f);
    }
};