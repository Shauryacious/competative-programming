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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        map<char, vector<string>> mp;
        for(auto w : wordDict) {
            mp[w[0]].pb(w);
        }

        vector<string> ans;


        auto f = [&](int idx, string& curr, auto&& f) -> void {
            if(idx == n){
                curr.pop_back(); // remove the last space
                ans.pb(curr);
                return;
            }
            if(idx > n) return;

            char c = s[idx];
            if(mp.find(c) == mp.end()) return; // no words start with this character

            for(auto x : mp[c]){
                int len = x.size();
                if(idx + len <= n){
                    if(s.substr(idx, len) == x) {
                        string prev = curr;
                        curr += x + " "; // add the word and a space
                        f(idx + len, curr, f); // recursive call
                        curr = prev; // backtrack
                    }
                }
            }

            return;
        };

        string curr = "";
        f(0, curr, f);

        return ans;
    }
};