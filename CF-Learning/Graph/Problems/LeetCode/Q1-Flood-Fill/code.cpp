#define vii vector<int>
#define pii pair<int, int>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sx, int sy, int nc) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> ans = a;
        int c = a[sx][sy];
        vii dx = {0, 0, 1, -1};
        vii dy = {1, -1, 0, 0};

        queue<pii> q;
        q.push({sx, sy});
        ans[sx][sy] = nc;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(a[nx][ny] != c) continue;
                if(ans[nx][ny] == nc) continue;

                ans[nx][ny] = nc;
                q.push({nx, ny});
            }
        }

        return ans;
    }
};