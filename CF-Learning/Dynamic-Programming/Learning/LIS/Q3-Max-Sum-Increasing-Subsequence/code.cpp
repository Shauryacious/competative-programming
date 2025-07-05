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
    int maxSumIS(vector<int>& a) {
        int n = a.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 5, -1));

        auto f = [&](int i, int last, auto&& f) -> int {
            if(i == n) return 0;

            if(dp[i][last + 1] != -1) return dp[i][last + 1];

            int ans = 0;

            if(last == -1 || a[i] > a[last]){
                ans = max(ans, a[i] + f(i + 1, i, f));
            }

            ans = max(ans, f(i + 1, last, f));

            return dp[i][last + 1] = ans;
        };

        return f(0, -1, f);
    }
};