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
    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 1);
        a.pb(1);

        int dp[305][305];
        memset(dp, 0, sizeof(dp));

        auto f = [&](int i, int j, auto && f) -> int {
            if(i > j) return 0; // Whenever i crosses j -> Base Case

            if(dp[i][j] != 0) return dp[i][j]; 

            int ans = 0;

            for(int k = i; k <= j; k++) {
                // Bursting the k-th balloon last in the range [i, j]
                int cost = a[i - 1] * a[k] * a[j + 1];
                int left = f(i, k - 1, f); // Bursting balloons in the left range
                int right = f(k + 1, j, f); // Bursting balloons in the right range

                ans = max(ans, cost + left + right);
            }

            return dp[i][j] = ans; 
        };

        // We start bursting balloons from index 1 to n (0-indexed, so we use 1 to n)
        return f(1, n, f); // Start bursting balloons from index 1 to n

    }
};