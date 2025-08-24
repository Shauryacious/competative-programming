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
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        auto cmp = [&](auto& a, auto& b) {
            if(a.size() == b.size()) {
                return a < b; // If sizes are equal, sort lexicographically
            }
            return a.size() < b.size();
        };

        sort(words.begin(), words.end(), cmp);

        auto isPredecessor = [&](string s1, string s2) -> bool {
            int n1 = s1.size(), n2 = s2.size();
            if(n1 + 1 != n2) {
                return false; // s2 must be exactly one character longer than s1
            }

            int i = 0, j = 0;
            while(j < n2){
                if(i < n1 && s1[i] == s2[j]) {
                    i++;
                }
                j++;
            }

            return i == n1; 
        };

        int off = 1;
        vector<vector<int>> dp(n + off + 1, vector<int>(n + 1, -1));

        auto f = [&](int prev, int i, auto && f) -> int {
            if(i == n) {
                return 0;
            }

            if(dp[prev + off][i] != -1) {
                return dp[prev + off][i];
            }

            int ans = 0;

            if(prev == -1 || isPredecessor(words[prev], words[i])) {
                ans = max(ans, 1 + f(i, i + 1, f));
            }

            ans = max(ans, f(prev, i + 1, f));

            return dp[prev + off][i] = ans;
        };

        return f(-1, 0, f);
    }
};
