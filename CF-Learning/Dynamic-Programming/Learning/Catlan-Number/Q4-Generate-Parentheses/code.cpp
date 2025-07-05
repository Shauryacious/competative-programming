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
    vector<string> generateParenthesis(int N) {
        set<string> ans;

        vector<set<string>> dp(N + 1);
        for(int i = 0; i <= N; i++) {
            dp[i].insert("");
        }
        dp[0].insert("");
        dp[1].insert("()");


        auto f = [&](int n, auto && f) -> set<string> {
            if(dp[n].find("") == dp[n].end()) {
                return dp[n];
            }

            string res = "";
            for(int i=0; i < n; i++){
                set<string> left = f(i, f);
                set<string> right = f((n - 1) - i, f);

                for(auto l : left) {
                    for(auto r : right) {
                        string temp = "(" + l + ")" + r;
                        if(temp.size() == 2 * N) {
                            ans.insert(temp);
                        }
                        dp[n].insert(temp);
                    }
                }
            }

            return dp[n];
        };


        auto x = f(N, f);

        vector<string> result(ans.begin(), ans.end());
        return result;
    }
};