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
    int largestIsland(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        // Step 1 : Transform the grid into a grid with size of components
        int ans = 0;

        vvii vis(n, vii(m, 0));

        vii dx = {0, 0, 1, -1};
        vii dy = {1, -1, 0, 0};

        auto dfs = [&](int x, int y, int& cnt, auto&& dfs) -> void {
            vis[x][y] = 1;
            cnt++;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;    
                if(g[nx][ny] == 0) continue;
                if(vis[nx][ny] == 1) continue;
                dfs(nx, ny, cnt, dfs);
            }
        };

        vvii vis2(n, vii(m, 0));
        vvii g2 = g;

        auto dfs2 = [&](int x, int y, int cnt, auto&& dfs2) -> void {
            vis2[x][y] = 1;
            g2[x][y] = cnt;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;    
                if(g[nx][ny] == 0) continue;
                if(vis2[nx][ny] == 1) continue;
                dfs2(nx, ny, cnt, dfs2);
            }
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 1 && vis[i][j] == 0) {
                    int cnt = 0;
                    dfs(i, j, cnt, dfs);
                    dfs2(i, j, cnt, dfs2);
                    ans = max(ans, cnt);
                }
            }
        }


        // Step 2: DSU (Disjoint Set Union)

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

        // Step 3: Union the components
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 0) continue;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(g[nx][ny] == 0) continue;
                    
                    int u = i * m + j;
                    int v = nx * m + ny;

                    Union(u, v);
                }
            }
        }


        // Step 4: Calculate the maximum size of the island after flipping one 0 to 1


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 1) continue;

                set<pair<int, int>> st;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(g[nx][ny] == 0) continue;

                    int u = nx * m + ny;
                    int pu = find(u);
                    st.insert({pu, g2[nx][ny]}); 
                }

                int cnt = 1; // for the current 0 we are flipping to 1
                for(auto& it : st) {
                    cnt += it.second; // add the size of the component
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};