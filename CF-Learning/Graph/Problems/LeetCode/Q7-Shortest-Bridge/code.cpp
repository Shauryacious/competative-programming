#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    vii dx = {1, -1, 0, 0};
    vii dy = {0, 0, 1, -1};


    void print(const vvii& g) {
        for(const auto& row : g) {
            for(int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
public:
    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        ii sx = -1, sy = -1;
        for(ii i = 0; i < n; i++) {
            for(ii j = 0; j < m; j++) {
                if(g[i][j] == 1) {
                    sx = i, sy = j;
                    break;
                }
            }
            if(sx != -1) break;
        }

        queue<pii> q;
        q.push({sx, sy});   
        g[sx][sy] = 2; // Mark the first island as visited
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(ii i = 0; i < 4; i++) {
                ii nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(g[nx][ny] == 0) continue; // Skip water cells
                if(g[nx][ny] == 2) continue; // Skip already visited cells
                if(g[nx][ny] == 1) {
                    g[nx][ny] = 2; // Mark as part of the first island
                    q.push({nx, ny});
                }
            }
        }
 
        queue<pii> q2;

        // print(g); 

        for(ii i = 0; i < n; i++) {
            for(ii j = 0; j < m; j++) {
                if(g[i][j] == 2) {
                    q2.push({i, j});
                }
            }
        }

        ii d = 0;
        while(!q2.empty()) {
            ii sz = q2.size();
            d++;
            while(sz--) {
                auto [x, y] = q2.front();
                q2.pop();
                for(ii i = 0; i < 4; i++) {
                    ii nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(g[nx][ny] == 1) return d-1; // Found the second island
                    if(g[nx][ny] == 0) {
                        g[nx][ny] = 2; // Mark as visited
                        q2.push({nx, ny});
                    }
                }
            }
        }

        return -1; // Should not reach here if input is valid
    }
};