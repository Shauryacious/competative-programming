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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        map<char, vector<string>> mp;
        for(auto w : wordDict) {
            mp[w[0]].pb(w);
        }

        int dp[n + 1];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int idx, auto && f) -> bool {
            if(idx == n) return true;
            if(idx > n) return false;

            if(dp[idx] != -1) return dp[idx];

            char c = s[idx];
            if(mp.find(c) == mp.end()) return false; // no words start with this character

            bool ans = false;

            for(auto x : mp[c]){
                int len = x.size();
                if(idx + len <= n){
                    if(s.substr(idx, len) == x) {
                        ans |= f(idx + len, f);
                    }
                }
            }

            return dp[idx] = ans;
        };

        return f(0, f);
    }
};