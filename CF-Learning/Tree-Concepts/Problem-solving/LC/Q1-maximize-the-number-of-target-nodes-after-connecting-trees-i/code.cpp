#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>


class Solution {
    void print(vii& v) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
public:
    vii maxTargetNodes(vvii& edges1, vvii& edges2, int k) {
        int n = edges1.size(), m = edges2.size();
        vvii adj1(n+1), adj2(m+1);
        for (int i = 0; i < n; ++i) {
            auto p = edges1[i];
            ii u = p[0], v = p[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (int i = 0; i < m; ++i) {
            auto p = edges2[i];
            ii u = p[0], v = p[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        auto dfs = [&](int u, int p, int& cnt, vvii& adj, int lvl, int k, auto && dfs) -> void{
            if(lvl <= k) {
                cnt++;
            }
            else {
                return;
            }

            for(auto v : adj[u]) {
                if(v != p) {
                    dfs(v, u, cnt, adj, lvl + 1, k, dfs);
                }
            }
        };

        vii v1(n+1, 0), v2(m+1, 0);

        for(int i = 0; i <= n; i++){
            int cnt = 0;
            dfs(i, -1, cnt, adj1, 0, k, dfs);
            v1[i] = cnt;
        }

        for(int i = 0; i <= m; i++){
            int cnt = 0;
            dfs(i, -1, cnt, adj2, 0, k-1, dfs);
            v2[i] = cnt;
        }

        ii mx = *max_element(v2.begin(), v2.end());

        // print(v1);
        // print(v2);

        for(int i = 0; i <= n; i++) {
            v1[i] += mx;
        }

        return v1;
    }
};