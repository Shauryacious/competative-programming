#define ll int
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define INF 1e9


class Solution {
    vll dx = {0, 0, 1, -1};
    vll dy = {1, -1, 0, 0};
public:
    int minimumObstacles(vector<vector<int>>& g) {
        ll n = g.size(), m = g[0].size();

        ll sx = 0, sy = 0, ex = n - 1, ey = m - 1;

        vvll dist(n, vll(m, INF));
        dist[sx][sy] = 0;

        set<pair<ll, pll>> pq;
        pq.insert({0, {sx, sy}});
        while (!pq.empty()) {
            auto [d, p] = *pq.begin();
            auto [x, y] = p;
            pq.erase(*pq.begin());

            for(ll i = 0; i < 4; i++) {
                ll nx = x + dx[i];
                ll ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if(g[nx][ny] + d < dist[nx][ny]) {
                    if(pq.count({dist[nx][ny], {nx, ny}})) {
                        pq.erase({dist[nx][ny], {nx, ny}});
                    }
                    dist[nx][ny] = g[nx][ny] + d;
                    pq.insert({dist[nx][ny], {nx, ny}});
                }
            }
        }

        if (dist[ex][ey] == INF) return -1;
        return dist[ex][ey];
    }
};