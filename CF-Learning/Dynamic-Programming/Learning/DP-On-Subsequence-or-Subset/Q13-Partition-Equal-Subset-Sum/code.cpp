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
    bool equalPartition(vector<int>& a) {
        int n = a.size();

        int off = 20000;
        int dp[101][20001];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int diff, auto && f) -> int {
            if(i == n){
                return diff == 0;
            }

            if(dp[i][diff + off] != -1) return dp[i][diff + off];

            int ans = 0;

            // Include the current element
            ans |= f(i + 1, diff + a[i], f);

            // Exclude the current element
            ans |= f(i + 1, diff - a[i], f);

            return dp[i][diff + off] = ans;
        };

        int ans = f(0, 0, f);

        return ans;
    }
};