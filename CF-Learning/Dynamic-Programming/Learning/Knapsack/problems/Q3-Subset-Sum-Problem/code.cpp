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
#define INF 1e18

class Solution {
public:
    bool isSubsetSum(vector<int>& a, int t) {
        int n = a.size();
        int dp[205][10005];

        memset(dp, -1, sizeof(dp));

        function<int(int,int)> f = [&](int i, int curr) -> int {
            if (curr > t) return 0;
            if (i == n) return curr == t;

            if (dp[i][curr] != -1) return dp[i][curr];

            int ans = 0;
            ans |= f(i + 1, curr + a[i]);  // take
            ans |= f(i + 1, curr);         // don't take

            return dp[i][curr] = ans;
        };

        return f(0, 0) == 1;
    }
};
