#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vvii ans(n, vii(m, -1));

        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vii dx = {0, 0, 1, -1};
        vii dy = {1, -1, 0, 0};

        ii d = 0;
        while (!q.empty()) {
            ii sz = q.size();
            d++;
            while(sz--){
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(ans[nx][ny] != -1) continue; // already visited
                    ans[nx][ny] = d;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};