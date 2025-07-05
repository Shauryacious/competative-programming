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
    int change(int t, vector<int>& a) {
        int n = a.size();

        vvii dp(n + 1, vii(t + 1, -1));

        auto f = [&](int i, int curr, auto && f) -> int {
            if(curr > t) return 0;
            if(i == n){
                return curr == t ? 1 : 0;
            }

            if(dp[i][curr] != -1) return dp[i][curr];

            int ans = 0;

            // Include the coin -> dont move the i pointer
            ans += f(i, curr + a[i], f);

            // Exclude the coin -> move the i pointer
            ans += f(i + 1, curr, f);

            return dp[i][curr] = ans;
        };

        return f(0, 0, f);
    }
};