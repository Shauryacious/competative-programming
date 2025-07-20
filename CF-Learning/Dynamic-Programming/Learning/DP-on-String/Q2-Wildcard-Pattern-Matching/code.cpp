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
#define vvpii vector<vpii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define ff first
#define ss second


class Solution {
  public:
    bool wildCard(string &s2, string &s1) {
        int n = s1.size(), m = s2.size();

        int dp[3005][3005];
        memset(dp, -1, sizeof(dp)); 

        auto f = [&](int i, int j, auto &&f) -> int {
            if(i >= n && j >= m) return 1;
            if(i >= n && j < m) return 0;
            if(j >= m) {
                for(int x = i; x < n; x++) {
                    if(s1[x] != '*') return 0;
                }
                return 1;
            }

            if(dp[i][j] != -1) return dp[i][j];

            int ans = 0;

            if(s1[i] == '?') {
                ans |= f(i + 1, j + 1, f);
            }
            else if(s1[i] == '*') {
                ans |= f(i + 1, j, f); // consider * as empty
                ans |= f(i, j + 1, f); // consider * as multiple characters
            }
            else if(s1[i] == s2[j]) {
                ans |= f(i + 1, j + 1, f);
            }
            else {
                return dp[i][j] = 0;
            }

            return dp[i][j] = ans;
        };

        return f(0, 0, f);
    }
};
