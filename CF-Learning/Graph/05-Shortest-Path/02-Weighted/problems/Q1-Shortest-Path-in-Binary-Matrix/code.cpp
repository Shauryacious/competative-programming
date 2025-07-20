// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<random>
#include<string>
#include<functional>
#include<iomanip>
#include<limits>
#include<array>
#include<utility>
#include<functional>
#include<iterator>
#include<cstring>

using namespace std;


#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e9

#define pii pair<int,int>
#define vpii vector<pii>
#define vii vector<int>
#define vvii vector<vii>
#define INF 1e9

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        if(g[0][0] == 1 || g[n-1][m-1] == 1) return -1;

        vpii didj = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        int d = 1;
        vvii dist(n, vii(m, INF));
        vvii vis(n, vii(m, 0));

        queue<pii> q;
        q.push({0, 0});
        dist[0][0] = 1;
        vis[0][0] = 1;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--){
                pii p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                if(i == n-1 && j == m-1) return d;
                for(auto [di, dj] : didj) {
                    int ni = i + di, nj = j + dj;
                    if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if(g[ni][nj] == 1) continue;
                    if(vis[ni][nj]) continue;
                    vis[ni][nj] = 1;
                    dist[ni][nj] = d;
                    q.push({ni, nj});
                }
            }
            d++;
        }

        if(dist[n-1][m-1] == INF) return -1;
        return dist[n-1][m-1];
    }
};
