#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>

class Solution {
public:
    void solve(vector<vector<char>>& b) {
        ii n = b.size(), m = b[0].size();
        queue<pii> q;
        vii dx = {0, 0, 1, -1};
        vii dy = {1, -1, 0, 0};
        for (ii i = 0; i < n; ++i) {
            for (ii j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && b[i][j] == 'O') {
                    q.push({i, j});
                    b[i][j] = 'E'; // Mark as escaped
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
                if(b[nx][ny] == 'X' || b[nx][ny] == 'E') continue;

                b[nx][ny] = 'E'; // Mark as escaped
                q.push({nx, ny});
            }
        }

        for (ii i = 0; i < n; ++i) {
            for (ii j = 0; j < m; ++j) {
                if (b[i][j] == 'O') {
                    b[i][j] = 'X'; // Mark as surrounded
                } else if (b[i][j] == 'E') {
                    b[i][j] = 'O'; // Restore escaped cells
                }
            }
        }
    }
};