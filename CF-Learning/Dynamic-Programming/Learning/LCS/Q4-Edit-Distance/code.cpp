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
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        int dp[505][505];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int j, auto && f) -> int {
            if(i == n || j == m) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int ans = 0;

            if(i < n && j < m && s1[i] == s2[j]) {
                ans = max(ans, 1 + f(i + 1, j + 1, f));
            }
            else{
                ans = max(ans, f(i + 1, j, f)); 
                ans = max(ans, f(i, j + 1, f));
            }

            return dp[i][j] = ans;
        };

        int lcs = f(0, 0, f);
        cout<<lcs<<endl;

        int ans = (n - lcs) + (m - lcs);
        return ans;
    }
};