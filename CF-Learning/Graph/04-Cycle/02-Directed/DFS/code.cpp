// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back

class Solution {
  public:
    bool isCyclic(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].pb(v);
        }

        vector<int> vis(n, 0), currvis(n, 0);
        bool hasCycle = false;

        auto dfs = [&](int u, auto &&dfs) -> void {
            vis[u] = 1;
            currvis[u] = 1;

            if(hasCycle) return;

            for(auto v : adj[u]) {
                if(vis[v] && currvis[v]) {
                    hasCycle = true;
                    return;
                }
                if(!vis[v]) {
                    dfs(v, dfs);
                    if(hasCycle) return;
                }
            }

            // backtrack: remove u from current recursion stack
            currvis[u] = 0;
        };

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, dfs);
            }
            if(hasCycle) break;
        }

        return hasCycle;
    }
};
