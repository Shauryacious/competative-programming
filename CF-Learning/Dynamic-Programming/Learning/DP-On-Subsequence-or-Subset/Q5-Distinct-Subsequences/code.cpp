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
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int j, auto && f) -> int {
            if(i >= n || j >= m){
                return 0;
            }

            if(dp[i][j] != -1){
                return dp[i][j];
            }

            int ans = 0;

            if(i < n && j < m && s[i] == t[j]){
                ans = 1 + f(i + 1, j + 1, f); 
            }

            // CASE 1: skip current character in s
            ans += f(i + 1, j, f);

            // CASE 2: skip current character in t 
            ans += f(i, j + 1, f);

            // CASE 3: skip current character in both s and t
            ans += f(i + 1, j + 1, f);


            return dp[i][j] = ans;
        };

        int ans = f(0, 0, f);
        return ans;
    }
};