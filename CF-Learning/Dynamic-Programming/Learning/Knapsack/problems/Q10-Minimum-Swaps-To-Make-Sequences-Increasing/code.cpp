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
    int minSwap(vector<int>& a1, vector<int>& a2) {
        a1.insert(a1.begin(), -1);
        a2.insert(a2.begin(), -1);

        int n = a1.size();

        int dp[100005][2];

        auto f = [&](int i, int swapped, auto && f) -> int {
            if(i == n) return 0;

            if(dp[i][swapped] != -1) return dp[i][swapped];

            int ans = INF;

            int prev1 = a1[i - 1];
            int prev2 = a2[i - 1];

            if(swapped) {
                swap(prev1, prev2);
            }

            // 1) try no-swap, if valid
            if (prev1 < a1[i] && prev2 < a2[i]) {
                ans = min(ans, f(i+1, 0, f));
            }
            // 2) try swapping at i, if valid
            if (prev2 < a1[i] && prev1 < a2[i]) {
                ans = min(ans, 1 + f(i+1, 1, f));
            }


            return dp[i][swapped] = ans;
        };

        memset(dp, -1, sizeof(dp));

        return f(1, 0, f);
    }
};