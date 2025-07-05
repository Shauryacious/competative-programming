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
#define INF 1e18

class Solution {
  public:
    vector<vector<string>> palinParts(string &s) {
        int n = s.size();

        auto isPalindrome = [&](string& s) -> bool {
            string t = s;
            reverse(t.begin(), t.end());
            return t == s;
        };

        vector<string> v;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string temp = s.substr(i, j - i + 1);
                if(isPalindrome(temp)){
                    v.push_back(temp);
                }
            }
        }

        vector<vector<string>> ans;

        int m = v.size();
        for(int i=0; i<(1 << m); i++) {
            vector<string> t;
            for(int j=0; j<m; j++) {
                if(i & (1 << j)) {
                    t.push_back(v[j]);
                }
            }

            string temp = "";
            for(auto x : t) {
                temp += x;
            }

            if(temp == s) {
                ans.push_back(t);
            }
        }

        if(ans.empty()) {
            return {{"-1"}};
        }

        return ans;

    }
};