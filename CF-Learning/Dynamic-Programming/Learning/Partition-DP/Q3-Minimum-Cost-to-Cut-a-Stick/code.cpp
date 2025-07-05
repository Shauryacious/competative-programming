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
    int minCost(int N, vector<int>& cuts) {
        cuts.pb(0);
        sort(all(cuts));
        cuts.pb(N);

        int dp[101][101];
        memset(dp, -1, sizeof(dp));


        auto f = [&](int i, int j, auto&& f) -> int {
            if(i > j) return 0; // no cuts possible

            if(dp[i][j] != -1) return dp[i][j];

            int ans = INF;
            for(int k=i; k<=j; k++){
                int cost = cuts[j+1] - cuts[i-1];
                int left = f(i, k-1, f);
                int right = f(k+1, j, f);

                ans = min(ans, cost + left + right);
            }

            return dp[i][j] = ans;
        }; 

        // cuts[0] = 0;
        // cuts[n-1] = N;

        int n = cuts.size();
        return f(1, n-2, f); 
    }
};