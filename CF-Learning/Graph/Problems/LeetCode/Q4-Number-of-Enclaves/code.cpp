#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>


class Solution {
public:
    int numEnclaves(vector<vector<int>>& a) {
        vvii b = a;
        ii n = b.size(), m = b[0].size();
        queue<pii> q;
        vii dx = {0, 0, 1, -1};
        vii dy = {1, -1, 0, 0};
        for (ii i = 0; i < n; ++i) {
            for (ii j = 0; j < m; ++j) {
                if(b[i][j] == 1){
                    if ((i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                        q.push({i, j});
                        b[i][j] = 2; // Mark as escaped
                    }
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (ii i = 0; i < 4; ++i) {
                ii nx = x + dx[i];
                ii ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(b[nx][ny] == 0 || b[nx][ny] == 2) continue;

                b[nx][ny] = 2; // Mark as escaped
                q.push({nx, ny});
            }
        }

        int ans = 0;
        for (ii i = 0; i < n; ++i) {
            for (ii j = 0; j < m; ++j) {
                if (b[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};