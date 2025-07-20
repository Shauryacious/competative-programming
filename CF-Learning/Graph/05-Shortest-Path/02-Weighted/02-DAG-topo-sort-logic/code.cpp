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
#define all(x) (x).begin(), (x).end()
#define INF 1e9

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vvpii adj(n);
        for(auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].pb({v, w});
        }

        vector<int> dist(n, INF);

        vector<int> topo;
        vii vis(n, 0);

        auto dfs = [&](int u, auto && dfs) -> void {
            vis[u] = 1;
            for(auto v : adj[u]) {
                if(!vis[v.first]) {
                    dfs(v.first, dfs);
                }
            }
            topo.pb(u);
        };

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, dfs);
            }
        }

        reverse(all(topo));

        dist[0] = 0; 

        for(auto u : topo) {
            for(auto p : adj[u]) {
                int v = p.first, wt = p.second;
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(dist[i] == INF) {
                dist[i] = -1; // If unreachable, return -1
            }
        }

        return dist;
    }
};
