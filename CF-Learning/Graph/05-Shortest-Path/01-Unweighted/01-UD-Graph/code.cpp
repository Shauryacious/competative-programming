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
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e9

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int s) {
        int n = adj.size();
        vector<int> dist(n, INF);
        dist[s] = 0;

        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        int d = 0;
        while (!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if(vis[v] == 0) {
                        vis[v] = 1;
                        dist[v] = min(dist[v], d + 1);
                        q.push(v);
                    }
                }
            }
            d++;
        }

        // If a node is unreachable, set its distance to -1
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};