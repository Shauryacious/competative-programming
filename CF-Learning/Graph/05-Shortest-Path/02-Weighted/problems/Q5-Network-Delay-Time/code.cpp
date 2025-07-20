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
#define ff first
#define ss second

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vvpii adj(n+1);

        for(auto t : times){
            int u = t[0], v = t[1], w = t[2];
            adj[u].pb({v, w});
        }

        vii dist(n+1, INF);

        set<pii> pq; // {dist, node}
        pq.insert({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());

            for(auto [v, w] : adj[u]){
                if(d + w < dist[v]){
                    if(pq.count({dist[v], v})){
                        pq.erase({dist[v], v});
                    }
                    dist[v] = d + w;
                    pq.insert({dist[v], v});
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(dist[i] == INF) return -1; // If any node is unreachable
        }


        return *max_element(dist.begin() + 1, dist.end()); // Exclude dist[0] as nodes are 1-indexed
    }
};