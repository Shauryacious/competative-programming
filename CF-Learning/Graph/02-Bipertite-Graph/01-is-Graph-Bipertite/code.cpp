#define vi vector<int>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vi vis(n);
        vi col(n, -1);
        bool ans = true;
        auto dfs = [&](int u, int c) -> void {
            vis[u] = 1;
            col[u] = c;
            for(auto v : adj[u]){
                if(vis[v] == 0){
                    dfs(v, c ^ 1);
                }
                else{
                    if(col[v] == col[u]){
                        ans = false;
                        return;
                    }
                }
            }
        };

        for(int i=0; i<n; i++){
            if(vis[i]==0) dfs(i, 0);
        }

        return ans;
    }
};