ll dfs(ll u, ll p, vvll& adj) {
    ll size = 1; // Include the current node itself
    for(auto v : adj[u]) {
        if(v != p) { // Avoid revisiting the parent
            size += dfs2(v, u, adj);
        }
    }
    return size;
}
