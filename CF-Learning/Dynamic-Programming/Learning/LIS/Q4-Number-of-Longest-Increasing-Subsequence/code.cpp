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

//WA
class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();

        int dp[2005][2005];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int last, auto && f) -> int {
            if(i == n) return 0;

            if(dp[i][last + 1] != -1) return dp[i][last + 1];

            int ans = 0;

            //Include the current element
            if(last == -1 || a[i] > a[last]) {
                ans = max(ans, 1 + f(i + 1, i, f));
            }

            //Exclude the current element
            ans = max(ans, f(i + 1, last, f));

            return dp[i][last + 1] = ans;
        };

        int lis = f(0, -1, f);

        // Now we need to count the number of LIS
        int ans = 0;

        memset(dp, -1, sizeof(dp));

        auto f2 = [&](int i, int last, int cnt, auto && f2) -> int {
            if(i == n) {
                return (cnt == lis) ? 1 : 0; 
            }

            if(dp[i][last + 1] != -1) return dp[i][last + 1];

            int ans = 0;

            // Include the current element
            if(last == -1 || a[last] < a[i]) {
                ans += f2(i + 1, i, cnt + 1, f2);
            }

            // Exclude the current element
            ans += f2(i + 1, last, cnt, f2);

            return dp[i][last + 1] = ans;
        };

        ans = f2(0, -1, 0, f2);

        return ans;
    }
};