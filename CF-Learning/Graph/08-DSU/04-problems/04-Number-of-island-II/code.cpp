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
#define vvpii vector<vpii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define ff first
#define ss second




class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        vvii g(n, vii(m, 0));

        vector<int> ans;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int N = n * m + 2;
        vector<int> par(N), rank(N, 0);

        iota(par.begin(), par.end(), 0); // parent[i] = i initially

        function<int(int)> find = [&](int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]);
        };

        auto Union = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;

            if (rank[px] > rank[py]) {
                par[py] = px;
            } else if (rank[py] > rank[px]) {
                par[px] = py;
            } else {
                par[py] = px;
                rank[px]++;
            }
        };


        int cnt = 0;

        for(auto p : op){
            int x = p[0], y = p[1];

            // if already visited -> return the current cnt
            if(g[x][y] == 1){
                ans.pb(cnt);
                continue;
            }

            // if not visited, mark it as visited -> inc cnt
            g[x][y] = 1;
            cnt++;

            // check all 4 directions
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if(g[nx][ny] == 1){
                    int u = x * m + y;
                    int v = nx * m + ny;

                    if(find(u) == find(v)) continue; // already connected

                    Union(u, v);
                    cnt--; // decrement the count of islands
                }
            }

            // add the current count of islands to the answer
            ans.pb(cnt);
        }
        
        return ans;
    }
};
