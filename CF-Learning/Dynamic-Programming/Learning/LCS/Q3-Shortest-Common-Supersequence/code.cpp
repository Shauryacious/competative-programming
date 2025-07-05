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
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int j, auto && f) -> int {
            if (i == n || j == m) return 0;

            if (dp[i][j] != -1) return dp[i][j];

            int ans = 0;

            if(s1[i] == s2[j]) {
                ans = max(ans, 1 + f(i + 1, j + 1, f));
            }
            else {
                ans = max(ans, f(i + 1, j, f));
                ans = max(ans, f(i, j + 1, f));
            }

            return dp[i][j] = ans;
        };

        int lcs_length = f(0, 0, f);
        int temp = lcs_length;

        string lcs = "";

        int i = 0, j = 0;
        while(temp > 0 && i < n && j < m) {
            if(dp[i][j] == temp && s1[i] == s2[j]) {
                lcs += s1[i];
                i++;
                j++;
                temp--;
            }
            else if(dp[i + 1][j] == temp) {
                i++;
            }
            else {
                j++;
            }
        }

        i = 0, j = 0;
        int k = 0;
        string ans = "";
        while(k < lcs.size()) {
            while(i < n && s1[i] != lcs[k]) {
                ans += s1[i];
                i++;
            }
            while(j < m && s2[j] != lcs[k]) {
                ans += s2[j];
                j++;
            }

            ans += lcs[k];
            i++;
            j++;
            k++;
        }

        while(i < n) {
            ans += s1[i];
            i++;
        }

        while(j < m) {
            ans += s2[j];
            j++;
        }

        return ans;
    }
};