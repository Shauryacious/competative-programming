#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string bs) {
        int n = s1.size();
        map<char, vector<char>> adj;
        for(ii i = 0; i < n; i++){
            char a = s1[i], b = s2[i];
            adj[a].pb(b);
            adj[b].pb(a);
        }

        auto dfs = [&](char u, vector<bool>& vis, char& mn, auto&& dfs) -> void{
            vis[u - 'a'] = true;
            mn = min(mn, u);
            for(char v : adj[u]){
                if(!vis[v - 'a']){
                    dfs(v, vis, mn, dfs);
                }
            }
        };

        int m = bs.size();
        for(ii i=0; i<m; i++){
            char ch = bs[i];
            vector<bool> vis(26, false);
            char mn = ch;
            dfs(ch, vis, mn, dfs);
            bs[i] = mn;
        }

        return bs;
    }   
};