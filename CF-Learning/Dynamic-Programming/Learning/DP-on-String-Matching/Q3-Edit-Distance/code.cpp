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
#define INF 1e9
#define ff first
#define ss second



class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        int dp[505][505];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int j, auto && f) -> int {
            //Base Case
            // If s1 is exhausted, we need to insert remaining chars of s2
            if (i == n) return m - j; 

            // If s2 is exhausted, we need to delete remaining chars of s1
            if (j == m) return n - i;

            // If both chars are same, no operation needed, move both pointers
            if (s1[i] == s2[j]) return f(i + 1, j + 1, f);

            if(dp[i][j] != -1) return dp[i][j];

            // If chars are different, we have 3 options:

            int ans = INF;

            //Case 1 : Insert a char -> keep i at same place
            ans = min(ans, 1 + f(i, j+1, f)); 

            //Case 2 : Delete a char -> keep j at same place
            ans = min(ans, 1 + f(i+1, j, f));

            //Case 3 : Replace a char -> move both i and j
            ans = min(ans, 1 + f(i+1, j+1, f));

            return dp[i][j] = ans;
        };

        int ans = f(0, 0, f);

        return ans;
    }
};