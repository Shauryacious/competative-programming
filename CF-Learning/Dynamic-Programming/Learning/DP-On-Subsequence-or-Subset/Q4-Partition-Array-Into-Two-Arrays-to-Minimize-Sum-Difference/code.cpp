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
    int minimumDifference(vector<int>& a) {
        int n = a.size();


        map<pii, int> dp;

        int off = 1e7;

        auto f = [&](int i, int diff, int l, int r, auto && f) -> int {
            if(i == n) {
                if(l == r) {
                    return abs(diff);
                }
                return INF;
            }

            if(dp.find({i, diff + off}) != dp.end()) {
                return dp[{i, diff + off}];
            }

            // Include the current element in the first subset
            int a1 = f(i + 1, diff + a[i], l+1, r, f);

            // Include the current element in the second subset
            int a2 = f(i + 1, diff - a[i], l, r+1, f);

            return dp[{i, diff + off}] = min(a1, a2);
        };

        return f(0, 0, 0, 0, f);
    }
};