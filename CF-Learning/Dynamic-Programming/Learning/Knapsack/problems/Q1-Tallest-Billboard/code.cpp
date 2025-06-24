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
    int tallestBillboard(vector<int>& a) {
        int n = a.size();

        int off = 5000; // offset to handle negative indices
        int dp[21][10001];
        memset(dp, -1, sizeof(dp));
        auto f = [&](int i, int diff, auto && f) -> int {
            if(i >= n){
                if(diff == 0) {
                    return 0; // if diff is zero, we can form a valid pair
                }
                return INT_MIN; // if diff is not zero, we cannot form a valid pair
            }

            if(dp[i][diff + off] != -1) {
                return dp[i][diff + off];
            }

            //take nothing
            int ans1 = f(i + 1, diff, f);

            //increase l1   
            int ans2 = a[i] + f(i + 1, diff + a[i], f);

            //increase l2
            int ans3 = a[i] + f(i + 1, diff - a[i], f);

            return dp[i][diff + off] = max({ans1, ans2, ans3});
        };


        return f(0, 0, f) / 2; // divide by 2 because we counted each pair twice
    }
};