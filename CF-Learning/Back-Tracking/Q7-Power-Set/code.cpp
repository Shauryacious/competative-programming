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
    vector<string> AllPossibleStrings(string s) {
        int n = s.size();

        vector<string> ans;

        auto f = [&](int i, string& curr, auto && f) -> void {
            if(i == n) {
                if (!curr.empty()) {
                    ans.push_back(curr);
                }
                return;
            }

            // Include the current character
            curr.push_back(s[i]);
            f(i + 1, curr, f);
            curr.pop_back();

            // Exclude the current character
            f(i + 1, curr, f);
        };

        string curr = "";
        f(0, curr, f);

        sort(all(ans));

        return ans;
    }
};