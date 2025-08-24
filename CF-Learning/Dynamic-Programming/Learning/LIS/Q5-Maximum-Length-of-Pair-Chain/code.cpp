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
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        //Step 1 : Sort to get them in Inc order
        sort(pairs.begin(), pairs.end());

        int dp[1005][1005];
        memset(dp, -1, sizeof(dp));
        int off = 1; //offset

        auto f = [&](int prev, int i, auto && f) -> int {
            if(i == n) return 0;

            if(dp[prev + off][i] != -1) return dp[prev + off][i];

            int ans = 0;

            if(prev == -1 || pairs[prev][1] < pairs[i][0]){
                ans = max(ans, 1 + f(i, i+1, f));
            }

            ans = max(ans, f(prev, i+1, f));

            return dp[prev + off][i] = ans;
        };

        int ans = f(-1, 0, f);
        return ans;
    }
};