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
    int minJumps(vector<int>& a) {
        int n = a.size();

        bool reached = false;

        int dp[10005];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, auto && f) -> int {
            if(i >= n - 1) {
                reached = true;
                return 0;
            }

            if(dp[i] != -1) {
                return dp[i];
            }

            int ans = INF;

            for(int j = 1; j <= a[i]; j++) {
                if(i + j <= n-1){
                    ans = min(ans, 1 + f(i + j, f));
                }
            }

            return dp[i] = ans;
        };
        
        int ans = f(0, f);
        return reached ? ans : -1;
    }
};
