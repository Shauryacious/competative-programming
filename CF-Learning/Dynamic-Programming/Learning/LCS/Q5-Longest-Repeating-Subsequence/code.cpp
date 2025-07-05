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
    int LongestRepeatingSubsequence(string &s) {
        int n = s.size();
        
        vvii dp(n + 1, vii(n + 1, -1));

        auto f = [&](int i, int j, auto && f) -> int {
            if(i == n || j == n) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int ans = 0;
            if(s[i] == s[j] && i != j){
                ans = max(ans, 1 + f(i + 1, j + 1, f));
            }
            else{
                ans = max(ans, f(i + 1, j, f));
                ans = max(ans, f(i, j + 1, f));
            }

            return dp[i][j] = ans;
        };
        
        return f(0, 0, f);
    }
};