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
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        if(g[0][0] == -1 || g[n - 1][m - 1] == -1) return 0;

        auto f = [&](int i, int j, auto && f) -> int {
            if(i == n-1 && j == m-1){
                return g[i][j];
            }

            int ans = 0;

            if(i + 1 < n && g[i + 1][j] != -1) {
                ans = max(ans, g[i][j] + f(i + 1, j, f));
            }

            if(j + 1 < m && g[i][j + 1] != -1) {
                ans = max(ans, g[i][j] + f(i, j + 1, f));
            }

            return ans;
        };
    }
};