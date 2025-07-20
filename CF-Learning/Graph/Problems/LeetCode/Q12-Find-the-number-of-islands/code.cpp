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
    int countIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();

        vvii vis(n, vii(m, 0));

        vii di = {-1, 1, 0, 0, -1, -1, 1, 1};
        vii dj = {0, 0, -1, 1, -1, 1, -1, 1};

        auto dfs = [&](int i, int j, auto && dfs) -> void {
            vis[i][j] = 1;

            for (int d = 0; d < 8; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];

                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if(vis[ni][nj]) continue;
                if(g[ni][nj] == 'W') continue;
                dfs(ni, nj, dfs);
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(g[i][j] == 'L' && vis[i][j] == 0) {
                    ans++;
                    dfs(i, j, dfs);
                }
            }
        }

        return ans;
    }
};