void dfs(ll u, ll p, vvll& adj, vll& heights){
    for(auto v : adj[u]){
        if(v != p){
            // Call dfs on all children
            dfs(v, u, adj, heights);

            // Calc Height
            heights[u] = max(heights[u], heights[v] + 1);
        }
    }
}