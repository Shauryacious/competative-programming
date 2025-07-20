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


class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int s) {
        vvpii adj(n);
        for(auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].pb({v, w});
        }

        vector<int> dist(n, INF);
        dist[s] = 0;

        set<pii> pq; // {node, distance}
        pq.insert({s, 0});

        while(!pq.empty()) {
            auto p1 = *pq.begin();
            int u = p1.first, d = p1.second;
            pq.erase(pq.begin());

            for(auto p2 : adj[u]) {
                int v = p2.first, w = p2.second;
                if(dist[u] + w < dist[v]){
                    if(pq.count({v, dist[v]})) {
                        pq.erase({v, dist[v]});
                    }

                    dist[v] = dist[u] + w;
                    pq.insert({v, dist[v]});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(dist[i] == INF) {
                dist[i] = -1; // If unreachable, return -1
            }
        }

        return dist;
    }
};