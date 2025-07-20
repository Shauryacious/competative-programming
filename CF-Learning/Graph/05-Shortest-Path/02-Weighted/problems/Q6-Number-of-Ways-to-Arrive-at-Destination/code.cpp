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
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define ff first
#define ss second

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vvpll adj(n);

        for(auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].pb({v, w});
            adj[v].pb({u, w}); // Since the roads are bidirectional
        }

        vector<ll> dist(n, INF);
        vector<ll> ways(n, 0);

        set<pll> pq; // {distance, node}
        pq.insert({0, 0}); // Start from node 0 with distance 0
        dist[0] = 0;
        ways[0] = 1; // There's one way to reach the starting node

        while(!pq.empty()){
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());

            for(auto& [v, w] : adj[u]) {
                if(d + w < dist[v]) {
                    if(pq.count({dist[v], v})) {
                        pq.erase({dist[v], v});
                    }
                    dist[v] = d + w;
                    ways[v] = ways[u]; // Update the number of ways to reach v
                    ways[v] %= MOD; // Ensure we don't overflow
                    pq.insert({dist[v], v});
                } 
                else if(d + w == dist[v]) {
                    ways[v] += ways[u]; // If we found another way to reach v with the same distance
                    ways[v] %= MOD; // Ensure we don't overflow
                }
            }
        }

        if(dist[n - 1] == INF) {
            return 0; // If the destination is unreachable
        }
        return ways[n - 1]; 
    }
};